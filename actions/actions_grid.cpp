#include "actions_grid.h"

ActionsGrid::ActionsGrid(FileSystemEntriesView &left,FileSystemEntriesView &right){
	/*move_button=new actions::MoveButton(left,right);
	this->attach(*move_button,0,0,1,1);*/
	copy_button=new actions::CopyButton(left,right);
	this->attach(*copy_button,0,1,1,1);
	/*delete_button=new actions::DeleteButton(left,right);
	this->attach(*delete_button,0,2,1,1);
	*/this->show();
}

ActionsGrid::~ActionsGrid(){
	//delete move_button;
	delete copy_button;
	//delete delete_button;
}
