#ifndef ACTION_BUTTON_H
#define ACTION_BUTTON_H
#define ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS FileSystemEntriesView &left,FileSystemEntriesView &right
#define ACTION_BUTTON_SHORT_ARGS left,right
namespace actions{
	class ActionButton:public Gtk::Button{
		protected:
			FileSystemEntriesView  *left_view,*right_view;
			Gtk::Entry *left_path_entry,*right_path_entry;
		public:
			ActionButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS){
							
				this->left_view=&left;
				this->right_view=&right;

				this->set_hexpand(true);
				this->set_halign(Gtk::ALIGN_FILL);
			}
		
	};
}
#endif
