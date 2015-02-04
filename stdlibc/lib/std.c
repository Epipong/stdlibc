/*
** std.c for std in /home/davy/Rendu/stdlibc/stdlibc
** 
** Made by davy tran
** Login   <tran_y@epitech.net>
** 
** Started on  Wed Feb  4 19:21:47 2015 davy tran
** Last update Wed Feb  4 19:21:52 2015 davy tran
*/

#include "std.h"

namespace	std = {
  &g_string, 
  &g_list, 
  &g_deque, 
  &g_map, 
  &g_vector, 
  &to_string
};
