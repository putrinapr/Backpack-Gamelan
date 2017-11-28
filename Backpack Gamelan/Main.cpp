#include "wx/wx.h"
#include "wx/wxprec.h"
#include "main.h"
#include "Frame.h"
#include "Title.h"

#ifndef WX_PRECOMP 
#include "wx/wx.h" 
#endif  

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	Title* drawPane;

	wxInitAllImageHandlers();

	Frame *frame = new Frame(wxT("Backpack Gamelan"));

	//drawPane = new Title(frame, wxT("TitleScreen.png"), wxBITMAP_TYPE_PNG);

	frame->Show(true);

	return true;
}