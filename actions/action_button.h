#ifndef ACTION_BUTTON_H
#define ACTION_BUTTON_H
namespace actions{
	class ActionButton:public Gtk::Button{
		protected:
			FileSystemEntriesView  *left_view,*right_view;
			Gtk::Entry *left_path_entry,*right_path_entry;
		public:
			ActionButton(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right){
							
				this->left_view=&left;
				this->right_view=&right;
				this->left_path_entry=&left_path;
				this->right_path_entry=&right_path;

				this->set_hexpand(true);
				//this->set_vexpand(true);
				this->set_halign(Gtk::ALIGN_FILL);
				//this->set_valign(Gtk::ALIGN_FILL);
			}
		
	};
}
#endif
