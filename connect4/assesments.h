// Evaluates the next choices
#ifndef _ASSESMENTS_H_
#define _ASSESMENTS_H_
#include <vector>
#include <algorithm>
#include <cassert>
#include "grid.h"
#include "tree_node.h"

namespace steffen_space{
    class assesment
    {
    private:
        const char empty_value = '.';

        int width;
        int height;
        int connect;

        grid_state current_grid;
        char ai_piece;
        tree_node<grid_state> state_space;
        int max_depth;

        // heuristic weights
        int ai_weight = 1;
        int opponent_weight = -10;
        float ai_4_weight = 100;
        float opponent_4_weight = -1000;
        float ai_3_weight = 1;
        float opponent_3_weight = -10;
        float ai_2_weight = 0.1;
        float opponent_2_weight = -1;

    public:
        assesment(int width, int height, int connect, char ai_piece, grid_state init_board);
        assesment(int width, int height, int connect, char ai_piece);
        //~assesment();

        std::vector< std::vector<char> >& get_grid();
        grid_state& get_grid_state();

        /// Utility assesment on an (x,y)
        /// (x, y) is new piece
        /// turn is the X or O turn
        /// grid is the board being evaluated
        bool utility(grid_state input_grid, int x, int y, int connect);
        bool utility(grid_state input_grid, int x, int y);
        bool utility(int x, int y);
    
        float heuristics(grid_state input_grid);
        float filter_assesment(std::vector< std::vector<char> > grid, std::vector< std::vector<int> > filter);

        int build_state_space();
        int build_state_space_recursive(tree_node<grid_state>* node, int current_depth, float alpha, float beta);

        int get_max_depth();
        void set_max_depth(int value);

        void update_weights();
    };
}

#endif
