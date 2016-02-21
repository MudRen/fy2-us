// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
int do_callwaiter(object room);
void create()
{
  set("short","˴��ɽׯ");
  set("long",@LONG
����Ǻպ�������˴��ɽׯ����˵˴�����ڴ˸�������
�����Ǽ��Ѳ��ö�֪��������ķ���ȷʵǧ���������ڴ���
һ�����������һ�����Ρ�����������������˿��š� 
(callwaiter)
LONG
  );
  set("exits",([
         "south":__DIR__"shanjiao.c",
               ]));
   
  setup();
}

void init()
{
   add_action("callwaiter","callwaiter");
}

int callwaiter()
{
   object room,*inv;
   mapping item;
   string room_file;
   int i;
   
   for(i=0;i<8;i++){
     room_file=sprintf("/open/mac/qianfo/private%d.c",i); 
     room=find_object(room_file);
// printf("%s,%s\n",room_file,file_name(room));
      inv=all_inventory(room);
//printf("%d\n\n",sizeof(inv));
     if(sizeof(inv))
       continue;
     else{
       return do_callwaiter(room);
       }
    }
   return notify_fail("���ķ��������������Ե�Ƭ�̡�\n");
}
int do_callwaiter(object room)
{
   object me,ob,item,mbox;
   string ob_file,item_file;
   string *terms,con_no,*terms_con;
   mapping homestaff,container; 
   int i,j,con_count;

   con_count=0;
   me=this_player();
   seteuid(geteuid(me));
   homestaff=me->query("homestaff");  
   tell_object(me,"һ�����С�ܹ�������������ķ��䡣\n");    

   if(mapp(homestaff) && sizeof(homestaff)){
      terms=keys(homestaff);  
      for (i=0;i<sizeof(terms);i++){
        ob_file=(string)me->query("homestaff/"+sprintf("%d",i));
        ob=new(ob_file);  
        ob->move(environment(me)); 
        if(ob->is_container()){
           con_no="container"+sprintf("%d",con_count); 
           container=me->query(con_no); 
           con_count++;
           if(mapp(container)&&sizeof(container)){
             terms_con=keys(container); 
             for(j=0;j<sizeof(terms_con);j++){
                item_file=(string)me->query(sprintf("%s/%d",con_no,j));
                item=new(item_file); 
                item->move(present(ob,environment(me)));
                me->delete(sprintf("%s/%d",con_no,j));
              }    
            } 
          }
        ob->move(room);
        me->delete("homestaff/"+sprintf("%d",i));
        me->save();
      }
   } 
//   me->move("/ftp/mac/private.c");
     me->move(room);
     tell_object(me,"Ŷ...����������� \n");    
     mbox=new(MAILBOX_OB);
     mbox->move(me);
   tell_object(me,"�ܿ�������ȥ��\n");
   return 1; 
}
