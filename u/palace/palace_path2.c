
inherit ROOM;

void create()
{
        set("short", "��ã����·");
        set("long", @LONG
ɽ�������･�����ߣ���Χ�ľ�����Ũ�����������֡�Ũ����
��ˮ��������͸��������ѣ����������������ܡ��⡭��������
��ͨ�����õ�·������ͨ������֮�ţ�
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_path3",
  "west" : __DIR__"palace_path1",
]));
        set("outdoors", "palace");

        setup();
}
void init()
{
        add_action("do_go","go");

}

int do_go()
{
if(random(2)){
this_player()->move(this_object());
return 1;
}
}

