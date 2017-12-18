echo "\x1b[36mVerification map vide :\x1b[0m"
./wolf3d maps/invalid/invalid_empty.wolf3d
echo "\n\x1b[36mVerification map size :\x1b[0m"
./wolf3d maps/invalid/invalid_x_y_sprites.wolf3d
echo "\n\x1b[36mVerification gnd and sky value :\x1b[0m"
./wolf3d maps/invalid/invalid_gnd_sky.wolf3d
echo "\n\x1b[36mVerification map data content :\x1b[0m"
./wolf3d maps/invalid/invalid_map_data.wolf3d
echo "\n\x1b[36mVerification map size on line X :\x1b[0m"
./wolf3d maps/invalid/invalid_size_on_line.wolf3d
echo "\n\x1b[36mVerification map neg number on map :\x1b[0m"
./wolf3d maps/invalid/invalid_neg_nbr_on_map.wolf3d
echo "\n\x1b[36mVerification number on border of the map :\x1b[0m"
./wolf3d maps/invalid/invalid_map_border.wolf3d
echo "\n\x1b[36mVerification charactere on map :\x1b[0m"
./wolf3d maps/invalid/invalid_character.wolf3d
echo "\n\x1b[36mVerification number of line on map :\x1b[0m"
./wolf3d maps/invalid/invalid_height.wolf3d