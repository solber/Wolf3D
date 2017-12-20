norminette srcs/
norminette includes/
make
clear
echo "\n\x1b[36mVerification open folder :\x1b[0m"
./wolf3d maps/
echo "\n\x1b[36mVerification open random file :\x1b[0m"
./wolf3d sounds/shotgun.wav
echo "\x1b[36mVerification map vide :\x1b[0m"
./wolf3d maps/invalid/invalid_empty.wolf3d
echo "\n\x1b[36mVerification map size :\x1b[0m"
./wolf3d maps/invalid/invalid_x_y_sprites.wolf3d
echo "\n\x1b[36mVerification gnd and sky value :\x1b[0m"
./wolf3d maps/invalid/invalid_gnd_sky.wolf3d
echo "\n\x1b[36mVerification map data content :\x1b[0m"
./wolf3d maps/invalid/invalid_map_data.wolf3d
echo "\n\x1b[36mVerification map size on line X :\x1b[0m"
./wolf3d maps/invalid/invalid_map_size_on_line.wolf3d
echo "\n\x1b[36mVerification map neg number on map :\x1b[0m"
./wolf3d maps/invalid/invalid_neg_nbr_on_map.wolf3d
echo "\n\x1b[36mVerification map border for y = 0 :\x1b[0m"
./wolf3d maps/invalid/invalid_map_border.wolf3d
echo "\n\x1b[36mVerification map border on y axis :\x1b[0m"
./wolf3d maps/invalid/invalid_map_border_0.wolf3d
echo "\n\x1b[36mVerification map border for y = map w :\x1b[0m"
./wolf3d maps/invalid/invalid_map_border_max.wolf3d
echo "\n\x1b[36mVerification map border for y = max h :\x1b[0m"
./wolf3d maps/invalid/invalid_map_border_hmax.wolf3d
echo "\n\x1b[36mVerification character on map :\x1b[0m"
./wolf3d maps/invalid/invalid_character.wolf3d
echo "\n\x1b[36mVerification number of line on map :\x1b[0m"
./wolf3d maps/invalid/invalid_height.wolf3d
echo "\n\x1b[36mVerification if it can spawn player :\x1b[0m"
./wolf3d maps/invalid/invalid_spawn_player.wolf3d
