// Room: /d/chuenyu/foot_b_mtn.c

inherit ROOM;

void create()
{
        set("short", "����ɽ��");
        set("long", @LONG
�����ڼ��ѵ�����Ψһͨ��ɽ����С·�ϡ�·�߶��źܶ���Ŀ
�����ľ�ʯ������������ǿ�Ĵ�ʯ���м��˳�����������
����Կ���ɽ���Ǳ��Ĵ���������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"foot_b_mtn",
  "up" : __DIR__"high_b_mtn",
]));
        set("outdoors", "chuenyu");

        setup();
        replace_program(ROOM);
}

