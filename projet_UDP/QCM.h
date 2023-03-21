#define NUM_QUESTIONS 2

typedef struct {
  char* question;
   char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
{"What is the capital of France?\nA:Paris\n B:Berlin\nC:Madrid\n D:London\nChoose your answer from A B C ou D\n",'A'},
{"What is the currency of Japan?\nA:Yen\n B:Dollar\nC:Euro\nD:Won\nChoose your answer from A B C ou D\n",'A'},
{ "Which country is the only one that is completely landlocked by another country?\nD:Lesotho\nA:Vatican City\nB:Liechtenstein\nC:Nepal\nChoose your answer from A B C or D\n", 'D' }
{ "Who wrote the novel '1984'?\nA:George Orwell\n B:J.R.R. Tolkien\nC:Mark Twain\nD:Ernest Hemingway\nChoose your answer from A B C or D\n", 'A' },
{ "What is the largest bone in the human body?\nA:Tibia\n B:Femur\nC:Humerus\nD:Skull\nChoose your answer from A B C or D\n", 'B' },
{ "Which planet is the second from the Sun?\nA:Mars\n B:Venus\nC:Earth\nD:Mercury\nChoose your answer from A B C or D\n", 'B' },
{ "What is the name of the phobia that means fear of spiders?\nA:Arachnophobia\n B:Claustrophobia\nC:Agoraphobia\nD:Acrophobia\nChoose your answer from A B C or D\n", 'A' },
{ "Which country has the largest population in the world?\nA:India\n B:China\nC:USA \nD:Indonesia \nChoose your answer from A B C or D \n", 'B' }
{ "Which country has the highest GDP per capita in the world?\nB:Qatar\nC:Luxembourg\nD:Singapore\nA:Norway\nChoose your answer from A B C or D\n", 'B' }
{ "Which country is the only one that has a flag with one color?\nC:Japan\nD:Libya\nA:China\nB:Canada\nChoose your answer from A B C or D\n", 'D' }
{ "Which country is the smallest by area in the world?\nC:Vatican City\nD:Monaco\nA:Nauru\nB:Tuvalu\nChoose your answer from A B C or D\n", 'C' }
{ "Which country is the only one that has a non-rectangular flag?\nB:Bhutan \nC:Cyprus \nD:Nepal \nA:Switzerland \nChoose your answer from A B C or D \n", 'D' }
{ "Which country is the only one that borders both Canada and Russia?\nD:USA\nA:Mongolia\nB:China\nC:Finland\nChoose your answer from A B C or D\n", 'D' }
{ "Which country has the most spoken languages in the world?\nA:India\nB:Papua New Guinea\nC:China\nD:Nigeria\nChoose your answer from A B C or D\n", 'B' }
{ "Which country is the only one that is also a continent?\nB:Australia\nC:Antarctica\nD:Africa\nA:Europe\nChoose your answer from A B C or D\n", 'B' }
{ "Which country has the longest coastline in the world?\nC:Canada\nD:Russia\nA:Indonesia\nB:Norway\nChoose your answer from A B C or D\n", 'C' }
{ "Which country has the most time zones in the world?\nA:Russia\nB:USA\nC:France\nD:China\nChoose your answer from A B C or D\n", 'C' }
{ "Which country is the largest producer of coffee in the world?\nB:Brazil\nC:Vietnam\nD:Colombia\nA:Ethiopia\nChoose your answer from A B C or D\n", 'B' }
{ "Which country is the birthplace of pizza?\nC:Italy\nD:Greece\nA:Egypt\nB:China\nChoose your answer from A B C or D\n", 'C' }
{ "Which country has the most Nobel laureates in the world?\nB:UK\nC:Germany\nD:USA\nA:France\nChoose your answer from A B C or D\n", 'D' }
{ "Which country is the only one that has a city that spans two continents?\nB:Russia \nC:Egypt \nD:Turkey \nA:Spain \nChoose your answer from A B C or D \n", 'D' }
{ "Which country is the only one that has English as its official language but not its most spoken language?\nC:Nigeria \nD:Ireland \nA:Australia \nB:India \nChoose your answer from A B C or D \n", 'D' }
  // Add more questions here
};