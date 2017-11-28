#ifndef _FRAME_H_
#define _FRAME_H_
#include <wx/wx.h>

class Title;
class Menu;

class Frame:public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	Title* titleScreen;
	Menu* menu;

	void fitWindowSize();
public:
	Frame(const wxString& title);
	void InitComponents();
	void ShowTitle();
	void ShowMenu();
};

#endif // _FRAME_H_