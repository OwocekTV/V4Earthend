#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <SFML/Graphics.hpp>
#include "P4A.h"
#include "Object.h"

using namespace std;

class AnimatedObject
{
    public:
    vector<Object> objects;
    float max_time;
    float cur_pos;

    ///OLD
    sf::Sprite s_wall;
    string current_animation = "idle";
    float current_frame = 0;
    float x = 0;
    float y = 245;
    float fps = 60;
    float width = 0;
    float scaleX = 1, scaleY = 1; ///TEMPORARY
    sf::Rect<float> hitBox;

    map<string,vector<sf::Texture>> animation_textures;

    vector<string> animation_name;
    vector<int> animation_frames;
    AnimatedObject();
    void loadAnim(std::string data, P4A handle);
    virtual void LoadConfig(std::string unitParamPath);
    virtual void Draw(sf::RenderWindow& window);
};

#endif // ANIMATEDOBJECT_H
