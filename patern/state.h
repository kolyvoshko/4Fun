#ifndef STATE
#define STATE

#include <stack>

class GameState
{
    GameState(){}
    virtual void handle() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual ~GameState(){}
};

class MenuState : public game_state
{
    MenuState(){}
    void handle(){}
    void update(){}
    void draw(){}
};

class Game
{
    std::stack<GameState*> states;
    void pushState(GameState* state){states.push(state);}
    void popState()
    {
        delete states.top();
        states.pop();
    }

    void changeState(GameState* state)
    {
        if (!states.empty())
            popState();

        pushState(state);
    }

    GameState* peekState()
    {
        if (states.empty()) return nullptr;
        return states.top();
    }

    void gameLoop()
    {
        while (true) {
            if(peekState()==nullptr) continue;
            peekState()->handle();
            peekState()->update();
            peekState()->draw();
        }
    }
};

#endif // STATE

