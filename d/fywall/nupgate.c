inherit ROOM;
void create()
{
        set("short", "������¥");
        set("long", @LONG
¥�ʷ��Σ��������Ǵ�����Ϣ����Ⱥ�������£���������Ⱥ��΢���еĲʴ�,
�Ϸ��Ƿ��Ƴǵ����ģ�����������Ҳ������ϡ�Ŀ������ƹ㳡���ĵ�������������
�ķ������಻�ϣ������С·��ϸС�����ߣ����������ڻ�ɫ�ķ���֮��.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : "/d/fy/ngate",
  "west" : __DIR__"nwall1",
  "east" : __DIR__"nwall10",
]));
        set("outdoors", "fengyun");
        setup();
        replace_program(ROOM);
}
