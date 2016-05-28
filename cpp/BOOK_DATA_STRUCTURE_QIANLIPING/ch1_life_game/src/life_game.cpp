#include <utility.h>
#include <life.h>
void main_life_game() {//FUNC
   Life a_board(10,10);
   a_board.init();
   //a_board.make_live(2,3);
   //a_board.make_live(1,3);
   a_board.make_live(2,4);
   a_board.make_live(1,4);
   a_board.make_live(0,4);
   //a_board.make_live(5,5);
   //a_board.make_dead(7,7);
   while (true) {
      a_board.show();
      a_board.update_neighbour_cnt();
      a_board.show_neighbour_cnt();
      if (!user_say_yes()) {break;}
      a_board.update();
   }
}
