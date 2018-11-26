#include"GameStateMachine.h"
GameStateMachine* GameStateMachine::s_pInstance = 0;
void GameStateMachine::changeState(GameState *pState)
{
	if (pState != NULL)
	{
		if (m_currentState != NULL) {
			m_prevState = m_currentState;
			m_currentState->onExit();
		}
		m_currentState = pState;
		m_currentState->onEnter();
	}
}

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}


void GameStateMachine::popState()
{
	changeState(m_prevState);
}

void GameStateMachine::update()
{
	if (m_currentState != NULL)
		m_currentState->update();
}

void GameStateMachine::render()
{
	if (m_currentState != NULL)
		m_currentState->render();
}
void GameStateMachine::collision()
{	
	if(m_currentState != NULL)
		m_currentState->Collision();
}
