//Kartikey Sharma
//1001659436
#include<iostream>
#include<gtkmm.h>
#include<vector>

class Game: public Gtk::Window
{
	public:
		Game()
		{

				set_default_size(550,350);
				set_title("Welcome to My Guessing Game");
				set_position(Gtk::WIN_POS_CENTER);

				Gtk::Box *MainVbox=Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
				add(*MainVbox);

				Gtk::MenuBar *MyMenuBar= Gtk::manage(new Gtk::MenuBar());
				MainVbox->pack_start(*MyMenuBar, Gtk::PACK_SHRINK, 0);

				Gtk::MenuItem *hint1= Gtk::manage(new Gtk::MenuItem("Abilities", true));
				MyMenuBar->append(*hint1);
				Gtk::Menu *Abilities= Gtk::manage(new Gtk::Menu());
				hint1->set_submenu(*Abilities);
				Gtk::MenuItem *timetravel= Gtk::manage(new Gtk::MenuItem("Time Travel", true));
				Abilities->append(*timetravel);
				Gtk::MenuItem *speed= Gtk::manage(new Gtk::MenuItem("Super Human Speed", true));
				Abilities->append(*speed);
				Gtk::MenuItem *force= Gtk::manage(new Gtk::MenuItem("Connection to the speed force", true));
				Abilities->append(*force);


				Gtk::MenuItem *hint2= Gtk::manage(new Gtk::MenuItem("Family & Friends", true));
				MyMenuBar->append(*hint2);
				Gtk::Menu *family= Gtk::manage(new Gtk::Menu());
				hint2->set_submenu(*family);
				Gtk::MenuItem *wife= Gtk::manage(new Gtk::MenuItem("Iris West (wife)", true));
				family->append(*wife);
				Gtk::MenuItem *friend1= Gtk::manage(new Gtk::MenuItem("Cisco Ramon (friend)", true));
				family->append(*friend1);
				Gtk::MenuItem *friend2= Gtk::manage(new Gtk::MenuItem("Oliver Queen (friend)", true));
				family->append(*friend2);


				Gtk::MenuItem *hint3= Gtk::manage(new Gtk::MenuItem("Villains", true));
				MyMenuBar->append(*hint3);
				Gtk::Menu *villains= Gtk::manage(new Gtk::Menu());
				hint3->set_submenu(*villains);
				Gtk::MenuItem *villain1= Gtk::manage(new Gtk::MenuItem("Eobard Thawn", true));
				villains->append(*villain1);
				Gtk::MenuItem *villain2= Gtk::manage(new Gtk::MenuItem("God Speed", true));
				villains->append(*villain2);
				Gtk::MenuItem *villain3= Gtk::manage(new Gtk::MenuItem("Gorilla Grodd", true));
				villains->append(*villain3);


			
				Gtk::Box *vBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
				MainVbox->add(*vBox);
				Gtk::Label *TextMsg2 = Gtk::manage(new Gtk::Label{"What is the name of this superhero?\n"});
				vBox->add(*TextMsg2);

				

				Gtk::Image *MyImage = Gtk::manage(new Gtk::Image{"superhero.jpeg"});
				vBox->add(*MyImage);
				MyImage->set_size_request(500,300);
				MyImage->show();

			

			
				Gtk::Box *hBox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_HORIZONTAL, 0));
				vBox->add(*hBox);
				Gtk::Box *vBox1 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
				hBox->add(*vBox1);
				Gtk::Box *vBox2 = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
				hBox->add(*vBox2);

				



				Gtk::Button* button = Gtk::manage(new Gtk::Button("OK"));
				button->set_size_request(275,20);
				vBox1->add(*button);


				Gtk::Entry *entry = Gtk::manage(new Gtk::Entry());
				entry->set_text("Enter your guess here");
				entry->set_size_request(275,20);
				
				vBox2->add(*entry);

				entry->show();


				Gtk::Button* button1 = Gtk::manage(new Gtk::Button("CANCEL"));
				button1->set_size_request(275,20);
				vBox1->add(*button1);

				std::string name = entry->get_text();

				button1->signal_clicked().connect(sigc::mem_fun(*this, &Game::cancel_Button_click));
				button->signal_clicked().connect(sigc::bind<Gtk::Entry*>(sigc::mem_fun(*this, &Game::ok_button_click), entry)); 

				entry->grab_focus();


				show_all_children();

		};
		void cancel_Button_click();
		void ok_button_click(Gtk::Entry*);

};

void Game::cancel_Button_click()
{
	hide();
}
void Game::ok_button_click(Gtk::Entry *name)
{
	Gtk::Button* button = Gtk::manage(new Gtk::Button("OK"));
	Gtk::MessageDialog *correct = new Gtk::MessageDialog(*this, "Your answer is <span fgcolor='#0000ff'>correct</span>!!", true,Gtk::MESSAGE_WARNING,Gtk::BUTTONS_NONE);
	correct->add_button("OK",Gtk::RESPONSE_CANCEL);

	button->signal_clicked().connect(sigc::mem_fun(*this, &Game::cancel_Button_click));
	Gtk::MessageDialog *incorrect = new Gtk::MessageDialog(*this, "Your answer is not <span fgcolor='#ff0000'>correct</span>.\nPlease try again", true, Gtk::MESSAGE_ERROR,Gtk::BUTTONS_NONE);
	incorrect->add_button("OK",Gtk::RESPONSE_CANCEL);
	if(name->get_text() == "flash")
	{
		int result = correct->run();
		correct->set_transient_for(*this);
		if(result ==Gtk::RESPONSE_CANCEL)
		{
			hide();
		}
		
	}
	else
	{
		int result = incorrect->run();
		incorrect->set_transient_for(*this);
		if(result ==Gtk::RESPONSE_CANCEL)
		{
			incorrect->close();
		}
	}

}

int main(int argc,char *argv[])
{
	auto app= Gtk::Application::create(argc,argv,"app.Window");
	Game MyWindow;
	app->run(MyWindow);
} 

