
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;
int ask_bing();
object creat_weapon();

void create()
{
	set_name("����", ({ "wind" }) );
	set("long",
		"��������µ�һ���˷��ơ�\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		"����̾�˿����������㵱����˭ѽ����Ҳ�ǿ������ \n",
		"����һ�����࿴���㣬˵����Ҫ�Ұ�æ����\n",
		"���ƺ����ߵؿ����㣬˵���ߣ���ذ����㣬�»����ǾͲ������ѣ�\n"
	}) );
	set("age", 22);
	set("combat_exp", 2000000);
	set("max_neili", 5000000);
	set("max_jing", 3000);
	set("max_qi", 3000);

	set("inquiry", ([
		"����"           : (: ask_bing :),
	]));

	setup();
}

int ask_bing()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/����");
		weapon = creat_weapon();
		weapon->move(me);
		message_vision(HIY "\nֻ���������쳤Х������һ���Ȼһ��������ڵ����ϳ�������������$N�����岻���ˣ�\n" NOR, me);
		return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/����");
	switch(mask)	{
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "��":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}