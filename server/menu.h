#ifndef MENU_H
#define MENU_H

#define MAX_MENU_ITEMS 12
#define MAX_MENU_LINE 32
#define MAX_COLUMNS 2

//----------------------------------------------------

struct MENU_INT
{
	BOOL bMenu;
	BOOL bRow[MAX_MENU_ITEMS];
	BOOL bPadding[8 - ((MAX_MENU_ITEMS + 1) % 8)]; 
};

class CMenu
{
private:
	
	BYTE m_byteMenuID;
	
	CHAR m_charTitle[MAX_MENU_LINE];
	CHAR m_charItems[MAX_MENU_ITEMS][MAX_COLUMNS][MAX_MENU_LINE];
	CHAR m_charHeader[MAX_COLUMNS][MAX_MENU_LINE];
	
	BOOL m_bInitedForPlayer[MAX_PLAYERS];
	MENU_INT m_MenuInteraction;
	
	float m_fXPos;
	float m_fYPos;
	float m_fCol1Width;
	float m_fCol2Width;
	BYTE m_byteColumns;
	//float fHeight
	
	BYTE m_byteColCount[MAX_COLUMNS];
	
public:

	CMenu(PCHAR pTitle, float fX, float fY, BYTE byteColumns, float fCol1Width, float fCol2Width);
	~CMenu(){};
	
	BYTE AddMenuItem(BYTE byteColumn, PCHAR pText);
	//void RemoveMenuItem(BYTE byteColumn, BYTE byteItem);
	void SetColumnTitle(BYTE byteColumn, PCHAR pText);
	
	void ResetForAll();
	
	void SetID(BYTE byteMenuID) { m_byteMenuID = byteMenuID; };
	
	void InitForPlayer(SACMPLAYER bytePlayerID);
	void ShowForPlayer(SACMPLAYER bytePlayerID);
	void HideForPlayer(SACMPLAYER bytePlayerID);
	
	void ResetPlayer(SACMPLAYER bytePlayerID)
	{
		if (bytePlayerID < MAX_PLAYERS) m_bInitedForPlayer[bytePlayerID] = FALSE;
	};
	void DisableInteraction() { m_MenuInteraction.bMenu = FALSE; };
	void DisableRow(BYTE byteRow) { m_MenuInteraction.bRow[byteRow] = FALSE; };
	
};

#endif // MENU_H

