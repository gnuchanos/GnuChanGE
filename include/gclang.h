#ifndef GCLANG
#define GCLANG

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef gcl
    #define gcl
#endif

/*
who, what did it, how, place, time

*/

//-------------------------- Pronoun ------------------------------
char *personal_pronouns[5][2] = {
    {"i", "ben"}, {"you", "sen"}, {"he", "male, o"}, 
    {"she", "female, o"}, {"it", "no gender, o"} };
char *reflexive_pronouns[5][2] = {
    {"me", "ben"}, {"you", "sen"}, {"him", "male, onun"},
    {"her", "female, onun"}, {"it", "no gender, onun"} };
char *possessive_pronouns[5][2] = { 
    {"mine", "benim"}, {"yours", "senin"}, {"his", "male, onun"},
    {"hers", "female, onun"}, {"it's", "no gender, bu"} };
char *intensive_pronouns[4][2] = { 
    {"myself", "kendim"}, {"yourself", "kendiniz"},
    {"himself", "male, kendisi"}, {"herself", "female, kendisi"} };
char *subject_pronouns[2][2] = { 
    {"we", "biz"}, {"they", "onlar"} };
char *object_pronouns[2][2] = { 
    {"us", "biz"}, {"them", "onların"} };
char *possessive_nouns[2][2] = { 
    {"ours", "bizlerin"}, {"theirs", "onların"} };
char *reflexive_nouns[2][2] = { 
    {"ourself", "kendimiz"}, {"themselves", "kendileri"} };



//-------------------------- verbs ------------------------------
char *be_verbs[6][2] = {
    {"am", "ben"}, {"is", "dir / -dır / -tir"},
    {"are", "dirler / -dırlar / -tirler"},
    {"not", "değil"},
    {"isn't", "değil"}, {"aren't", "değil"} };
char *past_be_verbs[2][2] = {
    {"was", "idi"}, {"were", "idi"} };
char *have_verbs[3][2] = {
    {"have", "sahip olmak"},
    {"has", "sahip olmak"}, {"had", "sahip olmak / -mış / -miş"} };
char *do_verbs[6][2] = {
    {"do", "yapmak"}, {"does", "yapmak"}, {"did", "yaptı"},
    {"don't", "yapma"}, {"doesn't", "yapma"}, {"didn't", "yapmadı"} };
char *future_be_verbs[2][2] = {
    {"shall", "olacak / -ecek"}, {"will", "olacak / -ecek"} };
char *conditional_verbs[2][2] = {
    {"should", "malı / -meli"}, {"would", "olurdu / -irdi / -ırdı"} };
char *possibility_verbs[3][2] = {
    {"may", "olabilir / -ebilir"}, {"might", "olabilir / -ebilir"},
    {"maybe", "olabilir"} };
char *necessity_verbs[4][2] = {
    {"must",  "meli / -malı"}, {"can", "yapabilir / -ebilir"},
    {"could", "yapabilir / -ebilir / -abilirdi"},
    {"can't", "yapamaz / -emez / -eme"} };


char *question_words[5][2] = {
    {"who", "kim"},
    {"whom", "kime / kimi"},
    {"whose", "kimin"},
    {"which", "hangi"},
    {"what", "ne"} };

char *demonstrative_pronouns[4][2] = {
    {"that", "bu / şu"},
    {"this", "bu"},
    {"these", "bunlar"},
    {"those", "şunlar / şunlar"} };



#endif