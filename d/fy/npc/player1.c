// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int custom();
void create()
{
        set_name("��С��", ({ "wang" }) );
        set("gender", "Ů��" );
        set("age", 39);
	set("combat_exp", 1517131);
	set("nickname","����аŮ");
	set("title","�����ɵڰ�ʮ��������");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1226);
	set("force",1226);
	set("force_factor",162/10);
	set("atman",731);
	set("mana",592);	
	set_skill("unarmed",150);
	set_skill("nine-moon-claw",118);
	map_skill("unarmed","nine-moon-claw");
	set_skill("dodge",199);
	set_skill("five-steps",99);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("hi");
return 1;
}
