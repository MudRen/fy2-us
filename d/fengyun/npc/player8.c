// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int custom();
void create()
{
        set_name("����", ({ "arwen" }) );
        set("gender", "Ů��" );
        set("age", 31);
	set("combat_exp", 3009368);
	set("title","�����ɵڰ�ʮ��������");
	set("nickname","��ľ��");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1460);
	set("force",2389);
	set("force_factor",206/10);
	set("atman",1300);
	set("mana",2800);	
	set_skill("unarmed",150);
	set_skill("nine-moon-claw",129);
	map_skill("unarmed","nine-moon-claw");
	set_skill("dodge",200);
	set_skill("five-steps",101);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("nip arwen");
return 1;
}
