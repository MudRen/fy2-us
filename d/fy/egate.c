inherit ROOM;
void create()
{
        set("short", "���ƶ�����");
        set("long", @LONG
���ƶ��Ÿ����ɣ���Լ�������࣬������ĳ�����������ȭͷ���С��������
�Ŷ���Լ���ɣ���Լÿ������ʱ���ͻ��ٱ����ء���������������׽��֮��Ĺ�
��ͨ�����Ŷ���������һ���ϳ�ǽ��խ�ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"east" : "/u/palace/palace_path1",
  "west" : __DIR__"ecloud5",
  "up" : "/d/fywall/eupgate",
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 2,
        __DIR__"npc/cloud_solider": 2, 
			]) );
        set("outdoors", "fengyun");
        setup();
}
int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me))
	{
	if( dir == "west" && ob=present("garrison", this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
			return notify_fail(ob->name()+"����ȵ��������ֱֳ�������Ƴǣ�\n");	
			
		}
	}
        if( dir == "up" && ob=present("garrison", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if((string)inv[i]->name() == "����ս��" && (int)inv[i]->query("equipped"))
                        {
			return 1;
                        }

                }
		return notify_fail(ob->name()+"����ȵ��������˵Ȳ����ϵǻ���ǽ��\n");
        }

        return 1;
	}
	else return 1;
}
