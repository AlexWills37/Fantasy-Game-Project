/* player.h
 *
 * Defines the Player's character that they control.
 * 
 * @author Alex Wills
 * @author Jhonder Abreus
 * @date April 7, 2023
 */
#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Graphics.hpp>
#include "LivingEntity.h"
#include "dragon.h"
/*
 * WizardSpells represents the fire that a dragon breaths to attack the player.
 */
class WizardSpells: public Entity {  // Since this is private, only WizardSpells and the friend class Dragon can call the entity methods
    friend class Player; // Allow Dragon class to access the WizardSpells's private methods/fields (such as .Draw())
    public:
        /*
         * Constructor for WizardSpells.
         * @param window - a pointer to the window to draw to
         * @param startingPos - the initial position of the fire
         */
        WizardSpells(sf::RenderWindow * window, sf::Texture * texture);
        /*
         * Default constructor. Initializes offScreen to true.
         */
        WizardSpells();
        
        
        /*
         * Moves the fire towards the air.
         */
        void MoveUp();

        bool offScreen1; // If this is true, the sprite is off screen and we can re-use it

        // const int textureWidth = 46;
        // const int textureHeight = 163;
};

class Player: public LivingEntity {


    public:
        /*
         * Creates the player as an Entity with a texture.
         */

        //Player(sf::RenderWindow * window, sf::Texture * texture, HealthBar * health);

        Player(sf::RenderWindow * window, sf::Texture * texture, HealthBar* healthBar, sf::Texture * fireTexture1);


        /*
         * Moves the player.
         */
        void Move(float deltaX, float deltaY);

        /*
         * Accesses the player's current score.
         */
        int GetScore();

        
        /*
        * Creates a wizard fire that launches it towrds the dragon
        */
        void CastSpell();


        void Draw();

        /*
         * Update's the player's state (score, collision, etc.).
         * Call this method every frame.
         */
        void FrameUpdate();


        // void ChangeHealth(int change);


        void DecreaseScore(int change);


        void Update();  

    private:
        int frameCounter;   // A counter to increase the player's score over time
        int score;          // The player's score
        float speed;

        //bool CheckCollission1(Dragon * dragon);

        static const int maxSpells = 10;  // How many fires can be on screen at once      
        WizardSpells spells[maxSpells];  // A list of the DragonFire objects that belong to this dragon.
        //Movement currentMovement;
        //int movementCounter;


};



#endif