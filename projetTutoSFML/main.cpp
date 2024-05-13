#include <iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include "Animation.h"
#include "Player.h"
#include<cstdlib>
#include<sstream>
#include<windows.h>
using namespace sf;
using namespace std;
const unsigned width = 1100;
const unsigned height = 900;
const float speed = 1000.0f;
int m = 0;
float delta = 0.035f;
float Gravity = 300;
float Velocity = 0;
float vitesse = 0;

int c = 0;
int c1 = 5;
int nb = 0;
std::string scor(double n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}
bool checkCollision(const Sprite& eggs, const RectangleShape& player)
{
    return eggs.getGlobalBounds().intersects(player.getGlobalBounds());
}
int main()
{
    RenderWindow window(VideoMode(width, height), "Mon jeu de poulet");

    window.setFramerateLimit(50);

    Music music;
    music.openFromFile("sound/nature.wav");
    music.setVolume(150);
    music.play();
    music.setLoop(true);

    SoundBuffer buffer;
    SoundBuffer buffer1;

    buffer.loadFromFile("sound/chicken.mp3");
    buffer1.loadFromFile("sound/break.wav");

    Sound sound;
    Sound sound1;
    sound1.setBuffer(buffer1);
    sound.setBuffer(buffer);

    Texture t_chicken1, t_chicken2, t_chicken3, t_chicken4;
    t_chicken1.loadFromFile("images/chicken1.png");
    t_chicken2.loadFromFile("images/chicken1.png");
    t_chicken3.loadFromFile("images/chicken1.png");
    t_chicken4.loadFromFile("images/chicken1.png");

    sf::Texture eggTexture;
    eggTexture.loadFromFile("images/chicken2.png");

    Texture t_backgroung;
    t_backgroung.loadFromFile("images/backk.png");


    RectangleShape back(Vector2f(1100, 900));
    back.setTexture(&t_backgroung);

    Sprite chickenS1, chickenS2, chickenS3, chickenS4;

    chickenS1.setTexture(t_chicken1);
    chickenS1.setScale(0.35f, 0.35f);
    chickenS1.setPosition(50, 10);

    chickenS2.setTexture(t_chicken2);
    chickenS2.setScale(0.35f, 0.35f);
    chickenS2.setPosition(330, 10);

    chickenS3.setTexture(t_chicken3);
    chickenS3.setScale(0.35f, 0.35f);
    chickenS3.setPosition(630, 10);

    chickenS4.setTexture(t_chicken4);
    chickenS4.setScale(0.35f, 0.35f);
    chickenS4.setPosition(900, 10);

    Texture playerTexture;
    playerTexture.loadFromFile("images/person3.png");

    Player player(&playerTexture, Vector2u(4, 1), 0.08f, speed);
    float deltaTime = 0.0f;
    Clock playerClock;

    Texture players;
    players.loadFromFile("images/player.png");

    Sprite player1;
    player1.setTexture(players);
    player1.setPosition(400, 600);

    Texture t_egg;
    t_egg.loadFromFile("images/egg.png");

    Sprite egg;
    egg.setTexture(t_egg);
    egg.setPosition(970, 100);

    sf::Sprite eggSprite;
    eggSprite.setTexture(eggTexture);
    eggSprite.setScale(0.35f, 0.35f);
    eggSprite.setPosition(50, 10);

    bool eggLaid = false; // Indique si l'œuf a été pondu

    Font myfont;
    Text score;
    Text sscore;
    Text essai;
    Text aessai;
    Text nbegg;
    Text eggt;
    myfont.loadFromFile("font/Pacifico.ttf");

    Texture tlose;
    tlose.loadFromFile("images/lose.png");

    Texture twins;
    twins.loadFromFile("images/win.png");

    Sprite wins(twins), lose(tlose);
    wins.setPosition(300, 270);
    lose.setPosition(300, 270);

    Texture start_t;
    start_t.loadFromFile("images/enter.png");

    RectangleShape start(Vector2f(1100, 900));
    start.setTexture(&start_t);

    while (!Keyboard::isKeyPressed(Keyboard::Enter)) {
        window.draw(start);
        window.display();
    }

    while (window.isOpen()) {

        score.setFont(myfont);
        score.setString("score :");
        score.setCharacterSize(40);
        score.setPosition(100, 830);

        sscore.setFont(myfont);
        sscore.setString(scor(c));
        sscore.setCharacterSize(40);
        sscore.setPosition(250, 830);

        essai.setFont(myfont);
        essai.setString("heart :");
        essai.setCharacterSize(40);
        essai.setPosition(760, 830);

        aessai.setFont(myfont);
        aessai.setString(scor(c1));
        aessai.setCharacterSize(40);
        aessai.setPosition(960, 830);

        eggt.setFont(myfont);
        eggt.setString("nb eggs :");
        eggt.setCharacterSize(40);
        eggt.setPosition(420, 830);

        nbegg.setFont(myfont);
        nbegg.setString(scor(nb));
        nbegg.setCharacterSize(40);
        nbegg.setPosition(620, 830);




        deltaTime = playerClock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::Left))
        {
            player.update(deltaTime);
            m = 1;
        }
        Velocity += Gravity * delta;
        vitesse = Velocity * delta;
        egg.move(0, vitesse);

        eggLaid = false;
        int valeurs[] = { 120, 400, 700, 970 };
        int nbValeurs = sizeof(valeurs) / sizeof(valeurs[0]); // Obtenir le nombre de valeurs
        int pos = rand() % nbValeurs; // Générer un indice aléatoire entre 0 et nbValeurs-1
        int valeurAleatoire = valeurs[pos];
        if ((egg.getPosition().y > 1000) && (egg.getPosition().x > 1000))
        {
            egg.setPosition(valeurAleatoire, 100);
            Velocity = 0;
            c = c + 100;
            nb++;
            if (!eggLaid) {
                eggSprite.setPosition(valeurAleatoire - 50, 10);
                eggLaid = true;
            }
            sound.play();
        }
        if ((egg.getPosition().y > 1000) && (egg.getPosition().x < 1000))
        {
            egg.setPosition(valeurAleatoire, 100);
            Velocity = 0;
            c1 = c1 - 1;
            c = c - 500;
            if (!eggLaid) {
                eggSprite.setPosition(valeurAleatoire - 50, 10);
                eggLaid = true;
            }
            sound.play();
        }

        if (checkCollision(egg, player.srpit()))
        {
            egg.setPosition(egg.getPosition().x + 1000, egg.getPosition().y + 1000);
            sound1.play();

        }

        if (c1 == 0) {
            window.draw(lose); window.display();
            Sleep(4000);
            c = 0;
            c1 = 5;
            nb = 0;
        }
        if (nb == 12) {
            window.draw(wins); window.display();
            Sleep(4000);
            c = 0;
            c1 = 5;
            nb = 0;
        }

        window.clear();
        window.draw(back);
        if (m == 1) { player.draw(window); }
        else { window.draw(player1); }
        if (eggLaid) { window.draw(eggSprite); }
        window.draw(chickenS1);
        window.draw(chickenS2);
        window.draw(chickenS3);
        window.draw(chickenS4);
        window.draw(egg);
        window.draw(score);
        window.draw(essai);
        window.draw(sscore);
        window.draw(aessai);
        window.draw(eggt);
        window.draw(nbegg);

        window.display();

    }
    return 0;
}
