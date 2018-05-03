#include "copy_button.h"
#include "../filesystem_management/linux/FileActions/execute_on_file.h"
#include "../filesystem_management/linux/linux_includes.h"
actions::CopyButton::CopyButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS):ActionButton(ACTION_BUTTON_SHORT_ARGS){
	this->set_label("Copy");
	this->signal_clicked().connect(sigc::mem_fun(this, &CopyButton::button_clicked) );
}


void actions::CopyButton::button_clicked(){
	std::cout<<"lolkl"<<std::endl;
	
	std::vector<Gtk::TreeModel::Path> rows=this->left_view->get_selection()->get_selected_rows();
	std::cout<<left_view->get_selection()->count_selected_rows()<<std::endl;
	for(Gtk::TreeModel::Path p:rows){
		std::cout<<p.to_string()<<std::endl;
		
	}
}

void actions::CopyButton::button_clicked_action(const Gtk::TreeModel::iterator& iter){
	Gtk::TreeModel::Row row = *iter;
	std::cout<<"lol"<<std::endl;
	std::cout<<row[this->left_view->model_columns->entry_name];
}
