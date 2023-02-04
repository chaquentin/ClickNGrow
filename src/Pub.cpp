/*
** EPITECH PROJECT, 2023
** ClickNGrow
** File description:
** Pub
*/

#include <iostream>
#include <vector>

void Pub()
{
    std::vector<std::string> videos = {"assets/pubs/axe.mp4", "assets/pubs/carrefour.mp4", "assets/pubs/tuneup.mp4"};
    std::string command = "vlc " + videos[rand() % videos.size()] + " --play-and-exit";
    int result = std::system(command.c_str());
}
