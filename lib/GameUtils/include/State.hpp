#pragma once

namespace ch {

    class State {
    public:
        virtual void init() = 0;

        virtual void handleInput() = 0;
        virtual void update(float dt) = 0;
        virtual void draw(float dt) = 0;  // deltatime for framerate independence

        virtual void pause() {  }
        virtual void resume() {  }
    };

}
