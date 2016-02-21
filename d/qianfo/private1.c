//mac's private.c
#include <room.h>
#define MAX_STAFF 50 

inherit ROOM;

void create()
{
  set("short","˽��");
  set("long",@LONG
     ����һ���������˽��������ǽ�Ϲҵ���һ������Ļ��һ���Ϻ��
     ��������һ������ͼ���ݳƶ�����Ʒ�����˾��Ѿ���ֵ���ǡ�����
     ��˵�ⷿ��İ����ˡ��뿪��֪ͨ��ࡣ(ring)
LONG
  );
  setup();
}

void init()
{
   add_action("do_leave","ring");
}

int do_leave() 
{
  object *inv,env,me,*inv_con,env_con,mbox; 
  string data,data_con;
  int i,staff_count,j,con_count,item_count;

  con_count=0;
  staff_count=0;
  me=this_player();
  env=environment(me);
  inv=all_inventory(env);

  if(sizeof(inv)) {
    if(sizeof(inv)>MAX_STAFF)
       return notify_fail("���ڷ��������̫��Ķ��������Ŷ��򲻿��ˡ�"); 
    for(i=0;i<sizeof(inv);i++){
     if(inv[i]->is_character());
     else{
      if(inv[i]->is_container())
       {
         item_count=0;
         env_con=present((string)inv[i]->query("id"),environment(me));
         inv_con=all_inventory(env_con);
         for(j=0;j<sizeof(inv_con);j++){
           if(inv_con[j]->is_character());
           else{ 
            data_con = base_name(inv_con[j])+".c";
            me->set("container"+sprintf("%d/%d",con_count,item_count),data_con);
            destruct(inv_con[j]);
            item_count=item_count+1;
            }       
          }
          con_count=con_count+1;
       }
      data=base_name(inv[i])+".c"; 
      me->set("homestaff/"+sprintf("%d",staff_count),data);
      destruct(inv[i]);
      staff_count=staff_count+1;
      }
    }
   }
   if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�����. \n");
                destruct(mbox);
        }

   tell_object(me,"�������������\n
   �����������������Ϲ��Ͼ��Ľӹ������е�Կ�ף���������˴��š�\n");  
   me->save();
   me->move("/open/mac/qianfo/shungeng.c");
   return 1;
 }
