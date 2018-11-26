#include "GameState.h"
class GameStateMachine
{
public:
	void changeState(GameState* pState);
	void popState();
	void pushState(GameState* pState);
	void update();
	void render();
	void collision();
	static GameStateMachine* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameStateMachine();
			return s_pInstance;
		}
		return s_pInstance;
	}
private:
	GameStateMachine() {};
	GameState* m_currentState;
	GameState* m_prevState;
	std::vector<GameState*>m_gameStates;
	static GameStateMachine* s_pInstance;
}; typedef GameStateMachine m_pGameStateMachine;
