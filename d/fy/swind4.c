inherit ROOM;
void create()
{
        set("short", "�Ϸ���");
        set("long", @LONG
����Ľֵ������ɾ�������������·�汻��ˮ��ù����羵���ֵ������
�߷��ߴ����ΰ�������Ǿ޸�լԺ��˫�˺ϱ�������ʮ��һ�꣬������������ߡ�
���ߵ�ǧ��¥�����ſ���ȸ�����ǵ�������ȴ�����ַǷ���ǧ��¥Ϊ�˷�����ˣ�
�����Ϸ��ֵĶ��濪��һ��ǧ�����̡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"swind5",
  "north" : __DIR__"swind3",
  "east" : __DIR__"qianyin",
  "west" : "/d/qianjin/qianjin",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
