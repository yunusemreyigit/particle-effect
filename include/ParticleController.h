//
// Created by yey on 11.06.2025.
//

#ifndef PARTICLECONTROLLER_H
#define PARTICLECONTROLLER_H
#include <Particle.h>
#include <ParticleViewer.h>
#include <memory>
#include <vector>


class ParticleController {
public:
    ParticleController();
    void move(Particle particle, glm::vec3 pos) const;
    void scale(Particle particle, glm::vec3 value) const;
    void rotate(Particle particle, glm::vec3 value) const;

    void createParticles(int particleNumber);
    void update(float deltaTime);
    void reset();

    void apply(Particle particle, glm::mat4 to, const float &deltaTime ) const;

    ParticleViewer* getView();
private:
    std::unique_ptr<ParticleViewer> particleViewer {};
    std::vector<Particle> particles;
};



#endif //PARTICLECONTROLLER_H
