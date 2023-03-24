#define NUM_QUESTIONS 22

typedef struct {
  char* question;
  char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
{"What is the capital of France?\n A:Paris\n B:Berlin\n C:Madrid\n D:London\n Choose your answer from A B C ou D\n",'A'},
{"What is the currency of Japan?\n A:Yen\n B:Dollar\n C:Euro\n D:Won\n Choose your answer from A B C ou D\n",'A'},
{ "Which country is the only one that is completely landlocked by another country?\n D:Lesotho\n A:Vatican City\n B:Liechtenstein\n C:Nepal\n Choose your answer from A B C or D\n", 'D' },
{ "Who wrote the novel '1984'?\n A:George Orwell\n B:J.R.R. Tolkien\n C:Mark Twain\n D:Ernest Hemingway\n Choose your answer from A B C or D\n", 'A' },
{ "What is the largest bone in the human body?\n A:Tibia\n B:Femur\n C:Humerus\n D:Skull\n Choose your answer from A B C or D\n", 'B' },
{ "Which planet is the second from the Sun?\n A:Mars\n B:Venus\n C:Earth\n D:Mercury\n Choose your answer from A B C or D\n", 'B' },
{ "What is the name of the phobia that means fear of spiders?\n A:Arachnophobia\n B:Claustrophobia\n C:Agoraphobia\n D:Acrophobia\n Choose your answer from A B C or D\n", 'A' },
{ "Which country has the largest population in the world?\n A:India\n B:China\n C:USA \n D:Indonesia \n Choose your answer from A B C or D \n", 'B' },
{ "Which country has the highest GDP per capita in the world?\n B:Qatar\n C:Luxembourg\n D:Singapore\n A:Norway\n Choose your answer from A B C or D\n", 'B' },
{ "Which country is the only one that has a flag with one color?\n C:Japan\n D:Libya\n A:China\n B:Canada\n Choose your answer from A B C or D\n", 'D' },
{ "Which country is the smallest by area in the world?\n C:Vatican City\n D:Monaco\n A:Nauru\n B:Tuvalu\n Choose your answer from A B C or D\n", 'C' },
{ "Which country is the only one that has a non-rectangular flag?\n B:Bhutan \n C:Cyprus \n D:Nepal \n A:Switzerland \n Choose your answer from A B C or D \n", 'D' },
{ "Which country is the only one that borders both Canada and Russia?\n D:USA\n A:Mongolia\n B:China\n C:Finland\n Choose your answer from A B C or D\n", 'D' },
{ "Which country has the most spoken languages in the world?\n A:India\n B:Papua New Guinea\n C:China\n D:Nigeria\n Choose your answer from A B C or D\n", 'B' },
{ "Which country is the only one that is also a continent?\n B:Australia\n C:Antarctica\n D:Africa\n A:Europe\n Choose your answer from A B C or D\n", 'B' },
{ "Which country has the longest coastline in the world?\n C:Canada\n D:Russia\n A:Indonesia\n B:Norway\n Choose your answer from A B C or D\n", 'C' },
{ "Which country has the most time zones in the world?\n A:Russia\n B:USA\n C:France\n D:China\n Choose your answer from A B C or D\n", 'C' },
{ "Which country is the largest producer of coffee in the world?\n B:Brazil\n C:Vietnam\n D:Colombia\n A:Ethiopia\n Choose your answer from A B C or D\n", 'B' },
{ "Which country is the birthplace of pizza?\n C:Italy\n D:Greece\n A:Egypt\n B:China\n Choose your answer from A B C or D\n", 'C' },
{ "Which country has the most Nobel laureates in the world?\n B:UK\n C:Germany\n D:USA\n A:France\n Choose your answer from A B C or D\n", 'D' },
{ "Which country is the only one that has a city that spans two continents?\n B:Russia \n C:Egypt \n D:Turkey \n A:Spain \n Choose your answer from A B C or D \n", 'D' },
{ "Which country is the only one that has English as its official language but not its most spoken language?\n C:Nigeria \n D:Ireland \n A:Australia \n B:India \n Choose your answer from A B C or D \n", 'D' }
  // Add more questions here
};