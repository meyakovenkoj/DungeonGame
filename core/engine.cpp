//
//  engine.cpp
//  classes-for-game
//
//  Created by Ivan Yakovenko on 02/12/2018.
//  Copyright © 2018 Ivan Yakovenko. All rights reserved.
//

#include "engine.hpp"

Engine::Engine()
{
	window.create(VideoMode(640, 480), "Dungeon");
	view.reset(FloatRect(0, 0, 640, 480));
	it.create("items1.png");
	p.create("player2.png", me.getX(), me.getY(), 32, 32);
	undead.create("undead.png", 0, 0, 32, 32);

	font.loadFromFile("extra/CyrilicOld.TTF");

	map.create("map.tmx");
	enemy.create("monster.png", 224, 256, 32, 32);
	menu.create(view);

	shootBuffer.loadFromFile("extra/audio/quietShaker.ogg");
	shoot.setBuffer(shootBuffer);

	dieBuffer.loadFromFile("extra/audio/death.ogg");
	die.setBuffer(dieBuffer);

	for (int i = 0; i < 100; i++)
	{
		Enemy buf(map);
		enemies.push_back(buf);
	}
	for (int i = 0; i < 100; i++)
	{
		game *buf;
		int c = rand() % 10;
		switch (c)
		{
		case 1:
		case 2:
		case 3:
			buf = new Armor();
			break;
		case 4:
		case 5:
		case 6:
			buf = new Weapon();
			break;
//		case 7:
//		case 8:
//		case 9:
//			buf = new Potion();
//			break;
		default:
			buf = new Potion();
			break;
		}
		buf->setCOORD(map);
		items.push_back(buf);
	}
}

bool Engine::start()
{

	p.getSprite().setPosition(me.getX(), me.getY());
	p.setX(me.getX());
	p.setY(me.getY());
	Vector2i pixelPos;
	Vector2f pos;
	bool select = false;

	while (window.isOpen())
	{
		view.setCenter(p.getX(), p.getY());

		window.setView(view);

		window.clear(Color(128, 106, 89));

		map.drawMap(window, view);

		drawEnemies();

		drawUndead();

		drawItem();

		window.draw(p.getSprite());

		menu.getInfo(me);

		menu.setPos(view);

		menu.draw(window);

		window.display();


        if (window.waitEvent(event))
		{
			switch (event.type)
			{

			case Event::Closed:
				window.close();
				break;

			case Event::MouseButtonPressed:
				if (static_cast<sf::Mouse::Button>(event.key.code) == Mouse::Left)
				{
					pixelPos = Mouse::getPosition(window);
					pos = window.mapPixelToCoords(pixelPos);
					if (p.getSprite().getGlobalBounds().contains(pos.x, pos.y))
					{
						p.getSprite().setColor(Color::Green);
						select = true;
					}
				}
				if (select)
					if (static_cast<sf::Mouse::Button>(event.key.code) == Mouse::Right)
					{
						p.getSprite().setColor(Color::White);
						pixelPos = Mouse::getPosition(window);
						pos = window.mapPixelToCoords(pixelPos);

						for (auto &elem : undeads)
							elem.setAim(pos.x, pos.y);
					}
				break;

			case sf::Event::KeyPressed:
				input();
				me.setPnt(p.getSprite().getPosition().x, p.getSprite().getPosition().y);
				updateEnemies();
				updateUndead();
				break;

			default:
				break;
			}
		}

		if (me.getHp() <= 0)
		{
			Text dead;
			dead.setFont(font);
			dead.setCharacterSize(30);
			dead.setFillColor(Color::Red);
			dead.setStyle(Text::Bold);
			dead.setString("\tYOU'RE DEAD\n\nPRESS ESC TO OUT\n\nPRESS TAB TO\nRESTART");
			dead.setPosition(view.getCenter().x - 150, view.getCenter().y - 50);
			window.draw(dead);
			window.display();
			die.play();
			while (window.waitEvent(event))
			{
				if (event.type == Event::Closed)
				{
					window.close();
					return false;
				}

				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.close();
					return false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Tab))
				{
					return true;
				}
			}
		}
	}
	return false;
}

void Engine::gameRunning()
{
	if (start())
	{
		gameRunning();
	}
}

void Engine::updateEnemies()
{
	int aiMove;
	int playerX = me.getX() / 32;
	int playerY = me.getY() / 32;
	int enemyX;
	int enemyY;

	for (int i = 0; i < enemies.size(); i++)
	{
		enemyX = enemies[i].getX() / 32;
		enemyY = enemies[i].getY() / 32;
		enemies[i].setAim(playerX * 32, playerY * 32);
		aiMove = enemies[i].getMove(playerX, playerY);

		switch (aiMove)
		{
		case 1: //Up
			processEnemyMove(i, enemyX, enemyY - 1);
			break;
		case 2: //Down
			processEnemyMove(i, enemyX, enemyY + 1);
			break;
		case 0: //Left
			processEnemyMove(i, enemyX - 1, enemyY);
			break;
		case 3: //Right
			processEnemyMove(i, enemyX + 1, enemyY);
			break;
		}
	}
}

void Engine::processEnemyMove(int enemyIndex, int targetX, int targetY)
{
	char moveTile = map.getchar(targetY, targetX);

	if ((targetX == p.getX() / 32) && (targetY == p.getY() / 32))
		return;

	switch (moveTile)
	{
	case '2':
		for (size_t i = 0; i < enemies.size(); i++)
		{
			if ((i != enemyIndex) && (targetX == enemies[i].getX() / 32) && (targetY == enemies[i].getY() / 32))
				return;
		}
		enemies[enemyIndex].setPnt(targetX * 32, targetY * 32);
		break;
	case '1':
		break;
		// something TODO
	default:
		break;
	}
}

void Engine::drawEnemies()
{
	for (auto &element : enemies)
	{
		enemy.getSprite().setPosition(element.getX(), element.getY());
		window.draw(enemy.getSprite());
	}
}

void Engine::updateUndead()
{
	int aiMove;
	int undeadX;
	int undeadY;

	for (int i = 0; i < undeads.size(); i++)
	{
		undeadX = undeads[i].getX() / 32;
		undeadY = undeads[i].getY() / 32;
		aiMove = undeads[i].getMove();

		switch (aiMove)
		{
		case 1: //Up
			processUndeadMove(i, undeadX, undeadY - 1);
			break;
		case 2: //Down
			processUndeadMove(i, undeadX, undeadY + 1);
			break;
		case 0: //Left
			processUndeadMove(i, undeadX - 1, undeadY);
			break;
		case 3: //Right
			processUndeadMove(i, undeadX + 1, undeadY);
			break;
		}
	}
}

void Engine::processUndeadMove(int undeadIndex, int targetX, int targetY)
{
	char moveTile = map.getchar(targetY, targetX);

	switch (moveTile)
	{
	case '2':
		for (int i = 0; i < undeads.size(); i++)
		{
			if ((i != undeadIndex) && (targetX == undeads[i].getX() / 32) && (targetY == undeads[i].getY() / 32))
				return;
		}
		undeads[undeadIndex].setPnt(targetX * 32, targetY * 32);
		break;
	case '1':
		break;
		// something TODO
	default:
		break;
	}
}

void Engine::drawUndead()
{
	for (auto &element : undeads)
	{
		undead.getSprite().setPosition(element.getX(), element.getY());
		window.draw(undead.getSprite());
	}
}

void Engine::drawItem()
{
	for (auto &element : items)
	{
		it.getSprite().setPosition(element->getX(), element->getY());
		switch (element->what())
		{
		case 0:
			it.getSprite().setTextureRect(IntRect(96, 0, 32, 32));
			break;
		case 1:
			it.getSprite().setTextureRect(IntRect(32, 0, 32, 32));
			break;
		case 2:
			it.getSprite().setTextureRect(IntRect(128, 0, 32, 32));
			break;
		default:
			break;
		}
		window.draw(it.getSprite());
	}
}

void Engine::processItems()
{
	int playerX = me.getX() / 32;
	int playerY = me.getY() / 32;
	for (int i = 0; i < items.size(); i++)
	{
		if ((playerX == items[i]->getX() / 32) && (playerY == items[i]->getY() / 32))
		{
			items[i]->makeEffect(me);
			items[i] = items.back();
			items.pop_back();
			i--;
		}
	}
}

void Engine::startscreen()
{
    Texture menuBackground;
    Text menuText1, menuText2, menuText3;
    menuText1.setFont(font);
    menuText1.setCharacterSize(30);
    menuText1.setStyle(Text::Bold);
    menuText1.setString("NEW GAME");
    menuText1.setPosition(100, 30);
    menuText2.setFont(font);
    menuText2.setCharacterSize(30);
    menuText2.setStyle(Text::Bold);
    menuText2.setString("LOAD GAME");
    menuText2.setPosition(100, 90);
    menuText3.setFont(font);
    menuText3.setCharacterSize(30);
    menuText3.setStyle(Text::Bold);
    menuText3.setString("EXIT");
    menuText3.setPosition(100, 150);
    menuBackground.loadFromFile("extra/images/knight.png");
    Sprite menuBg(menuBackground);
    bool isMenu = 1;
    int menuNum = 0;
    std::string str;
    menuBg.setPosition(640, 0);
    menuBg.setScale(-0.9, 0.9);

    while (isMenu)
    {
        if (window.waitEvent(event))
        {
            menuText1.setFillColor(Color::White);
            menuText2.setFillColor(Color::White);
            menuText3.setFillColor(Color::White);
            menuNum = 0;

            if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
            {
                menuText1.setFillColor(Color::Red);
                menuNum = 1;
            }
            if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window)))
            {
                menuText2.setFillColor(Color::Red);
                menuNum = 2;
            }
            if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))
            {
                menuText3.setFillColor(Color::Red);
                menuNum = 3;
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                event.mouseButton.~MouseButtonEvent();
                switch (menuNum)
                {
                    case 1:
                        me.load("init.txt");
                        isMenu = false;
                        break;

                    case 2:
                        str.erase();
                        window.clear(Color(128, 106, 89));
                        loadScreen(str);
                        me.load(str);
                        str.erase();
                        isMenu = false;
                        break;

                    case 3:
                        window.close();
                        isMenu = false;
                        break;

                    default:
                        break;
                }
            }
        }
        window.clear(Color(128, 106, 89));

        window.draw(menuBg);
        window.draw(menuText1);
        window.draw(menuText2);
        window.draw(menuText3);

        window.display();
    }
}

void Engine::loadScreen(std::string &str)
{
    Vector2f origin = {(window.getView().getCenter().x - window.getSize().x / 2), (window.getView().getCenter().y - window.getSize().y / 2)};
    Text save1, save2, save3, save4;
    save1.setFont(font);
    save1.setCharacterSize(30);
    save1.setStyle(Text::Bold);
    save1.setString("SLOT 1");
    save1.setPosition(origin.x + 100, origin.y + 30);
    save2.setFont(font);
    save2.setCharacterSize(30);
    save2.setStyle(Text::Bold);
    save2.setString("SLOT 2");
    save2.setPosition(origin.x + 100, origin.y + 90);
    save3.setFont(font);
    save3.setCharacterSize(30);
    save3.setStyle(Text::Bold);
    save3.setString("SLOT 3");
    save3.setPosition(origin.x + 100, origin.y + 150);
    save4.setFont(font);
    save4.setCharacterSize(30);
    save4.setStyle(Text::Bold);
    save4.setString("SLOT 4");
    save4.setPosition(origin.x + 100, origin.y + 210);
    bool isLoad = 1;
    str = "init.txt";
    window.clear(Color(128, 106, 89));

    while (isLoad)
    {
        if (window.waitEvent(event))
        {
            save1.setFillColor(Color::White);
            save2.setFillColor(Color::White);
            save3.setFillColor(Color::White);
            save4.setFillColor(Color::White);
            window.clear(Color(128, 106, 89));

            if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window)))
            {
                save1.setFillColor(Color::Red);
                str = "save1.txt";
            }
            if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window)))
            {
                save2.setFillColor(Color::Red);
                str = "save2.txt";
            }
            if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window)))
            {
                save3.setFillColor(Color::Red);
                str = "save3.txt";
            }
            if (IntRect(100, 210, 300, 50).contains(Mouse::getPosition(window)))
            {
                save4.setFillColor(Color::Red);
                str = "save4.txt";
            }

            if (Mouse::isButtonPressed(Mouse::Left))
            {
                isLoad = false;
            }
        }

        window.draw(save1);
        window.draw(save2);
        window.draw(save3);
        window.draw(save4);

        window.display();
    }
}

void Engine::input()
{
    if (Keyboard::isKeyPressed(Keyboard::Escape))
    {
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        p.control(1, map);
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        p.control(0, map);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        p.control(3, map);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        p.control(2, map);
    }

    if (Keyboard::isKeyPressed(Keyboard::LShift))
    {

        processItems();
    }

    if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        for (int i = 0; i < enemies.size(); i++)
        {
            if (enemies[i].distAim() / 32 <= 1)
            {

                shoot.play();
                me.getLog().str("");
                me.getLog().clear();
                me.takeDamage(enemies[i].attack());
                int c = me.attack();
                me.getLog() << "You try to hit\nmonster \nwith " << c << '\n';
                int exp = enemies[i].takeDamage(c);
                me.addExperience(exp);
                me.getLog() << "You earned " << exp << "\nof experience\n";
                if (!enemies[i].isAlive())
                {
                    Undead buf(enemies[i]);
                    undeads.push_back(buf);
                    enemies[i] = enemies.back();
                    enemies.pop_back();
                    i--;
                }
            }
        }
    }

    if (Keyboard::isKeyPressed(Keyboard::Tab))
    {
        std::string save;
        loadScreen(save);
        me.save(save);
        save.erase();
    }
}

Engine::~Engine() = default;
