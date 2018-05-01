#ifndef ACTIONS_GRID_H
#define ACTIONS_GRID_H
#include <gtkmm-3.0/gtkmm.h>
#include "move_button.h"
#include "copy_button.h"
#include "delete_button.h"
class ActionsGrid:public Gtk::Grid{
	private:
		actions::MoveButton *move_button;
		actions::CopyButton *copy_button;
		actions::DeleteButton *delete_button;
	public:
		ActionsGrid(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right){
			move_button=new actions::MoveButton(left_path,right_path,left,right);
			this->attach(*move_button,0,0,1,1);
			copy_button=new actions::CopyButton(left_path,right_path,left,right);
			this->attach(*copy_button,0,1,1,1);
			delete_button=new actions::DeleteButton(left_path,right_path,left,right);
			this->attach(*delete_button,0,2,1,1);
			this->show();
		}
		
		~ActionsGrid(){
			delete move_button;
			delete copy_button;
			delete delete_button;
		}
};



#endif
