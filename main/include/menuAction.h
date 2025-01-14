#ifndef UTILS_MenuAction
#define UTILS_MenuAction

#define MENUACTION_MenuLink 0
#define MENUACTION_SetValue 1

class MenuAction {
private:
    unsigned int menuActionType;
    void* target;// can be any data type, depends on the MENUACTION_TYPE

public:
    void* GetTarget();
    MenuAction(unsigned int menuActionType);
    unsigned int MenuActionType();
    void SetTarget(void* newTarget);
};

#endif