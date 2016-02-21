// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int custom();
void create()
{
        set_name("����", ({ "jiao" }) );
        set("gender", "Ů��" );
        set("age", 30);
	set("combat_exp", 1064180);
	set("nickname","��Ů");
	set("title","����һ������������");
        set("chat_chance", 2);
        set("chat_msg", ({
		(: custom :)	
        }) );

        set("attitude", "friendly");
	set("max_force",1270);
	set("force",1226);
	set("force_factor",159/10);
	set("atman",731);
	set("mana",592);	
	set_skill("unarmed",150);
	set_skill("bloodystrike",130);
	map_skill("unarmed","bloodystrike");
	set_skill("dodge",199);
	set_skill("five-steps",99);
	map_skill("dodge","five-steps");
        setup();
        carry_object("/obj/cloth")->wear();

}

int custom()
{
command("smile");
return 1;
}
