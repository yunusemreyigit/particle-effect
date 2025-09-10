//
// Created by yey on 04.06.2025.
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

struct Particle {
public:
    Particle(glm::vec3 vel): velocity(vel){};
    void update(float deltaTime)  // invoke every frame
    {
        position += velocity * deltaTime;
        // std::cout << position.x << "\t" << position.y << "\t" << position.z << "\n";
        decreaseLifetime(deltaTime);
        if (active == false)
        {
            size = 0.0f;
        }
    }
    void decreaseLifetime(const float deltaTime) {
        lifeTime -= deltaTime;
        // std::cout << "Lifetime is " << lifeTime << ", deltaTime is " << deltaTime << std::endl;
        if (lifeTime <= 0.0f) {
            active = false;
            reset();
        }
    }
    void reset() {
        std::cout << "resetting particle" << std::endl;
        lifeTime = 1.0f;
    }
    float getSize() const
    {
        return size;
    }

    glm::vec3 getPosition() const
    {
        return position;
    }

private:
    float size{ .2f };
    glm::vec3 position{ 0.0f };
    glm::vec3 velocity{ .0f };
    float lifeTime{ 1.0f };

    // glm::vec4 color;
    bool active { true };
};
#endif //PARTICLE_H
