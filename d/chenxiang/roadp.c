
inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١����������
���綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����
һ���������۵Ĺٵ��������Ͷ�����չ��
LONG
        );
        set("exits", ([ 
  "northwest" : "/u/quicksand/desert2",
  "southeast" : __DIR__"road",
]));
        set("outdoors", "chenxiang");

        setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(5)){
this_player()->move(this_object());
return 1;
}
}


