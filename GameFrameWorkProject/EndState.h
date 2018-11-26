#include"GameState.h"

class EndState : public GameState
{
public:
	EndState() {};
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual void Collision();
	virtual std::string getStateID() const { return s_menuID; }
	static EndState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new EndState();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void HandleInput();

private:
	static const std::string s_menuID;
	static EndState* s_pInstance;
}; typedef EndState EndState;