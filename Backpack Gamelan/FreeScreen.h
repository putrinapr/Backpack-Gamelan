#include <wx/wx.h>
#include <wx/sizer.h>
#include "Frame.h"

class FreeScreen : public wxPanel
{
	wxBitmap image;

public:
	FreeScreen(Frame* parent, wxString file, wxBitmapType format);
	~FreeScreen();

	void OnPauseButtonClick(wxCommandEvent& event);

	void paintEvent(wxPaintEvent & evt);
	void paintNow();

	void render(wxDC& dc);

private:
	Frame *parentFrame;
	DECLARE_EVENT_TABLE()
};