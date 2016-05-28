#include <utility.h>

class Life {
   public:
      Life(int ,int );
      void update();
      void init();
      void make_live(int,int);
      void make_dead(int,int);
      void show();
      void show_neighbour_cnt();
      void update_neighbour_cnt();
      int calc_neighbour_cnt(int,int);
   protected:
      int width;
      int cout_table_width;
      int height;
      int SHOW_WIDTH;
      int SHOW_HEIGHT;
      int origin_col;
      int origin_row;
      int big_col;
      int big_row;
      bool matrix[100][100];
      int neighbour_cnt[100][100];
};
