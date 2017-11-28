#include <wx/wx.h>
#include <wx/sizer.h>
#include "Frame.h"

class Title : public wxPanel
{
	wxBitmap image;

public:
	Title(Frame* parent, wxString file, wxBitmapType format);
	~Title();

	void OnStartButtonClick(wxCommandEvent& event);

	void paintEvent(wxPaintEvent & evt);
	void paintNow();

	void render(wxDC& dc);

	// some useful events
	/*
	void mouseMoved(wxMouseEvent& event);
	void mouseDown(wxMouseEvent& event);
	void mouseWheelMoved(wxMouseEvent& event);
	void mouseReleased(wxMouseEvent& event);
	void rightClick(wxMouseEvent& event);
	void mouseLeftWindow(wxMouseEvent& event);
	void keyPressed(wxKeyEvent& event);
	void keyReleased(wxKeyEvent& event);
	*/

private:
	Frame *parentFrame;
	DECLARE_EVENT_TABLE()
};