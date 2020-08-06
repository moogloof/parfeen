#include <iostream>
#include <string>
#include <utils/display.h>

// Display info
void Display(int width, int height, double **coords, int coord_len, int scale) {
    int relative_coord[2];
    bool graph[height][width];

    // Reset graph
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            graph[i][j] = false;

    // Generate filled spots on graph
    for (int i = 0; i < coord_len; i++) {
        // Get relative coords
        relative_coord[0] = static_cast<int>(coords[i][0] / scale);
        relative_coord[1] = static_cast<int>(height - (coords[i][1] / scale) - 1);

        // Set filled spots on graph if inside bounds
        if (relative_coord[0] < width && relative_coord[1] < height)
            if (relative_coord[0] >= 0 && relative_coord[1] >= 0)
                graph[relative_coord[1]][relative_coord[0]] = true;
    }

    // Display graph
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (graph[i][j])
                // Fill in spot if marked on graph
                std::cout << DisplayChars::filled_char;
            else
                // Set as empty otherwise
                std::cout << DisplayChars::empty_char;
        }
        // Start a new row
        std::cout << std::endl;
    }
}

