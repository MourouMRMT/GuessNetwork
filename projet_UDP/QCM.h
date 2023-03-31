#define NUM_QUESTIONS 22

typedef struct {
  char* question;
  char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
 {"What is the capital of France?\n A:Paris\n B:Berlin\n C:Madrid\n D:London\n Choose your answer from A B C ou D\n", 'A'},
  {"What is the currency of Japan?\n A:Yen\n B:Dollar\n C:Euro\n D:Won\n Choose your answer from A B C ou D\n", 'A'},
  {"Which country is the only one that is completely landlocked by another country?\n A:Vatican City\n B:Liechtenstein\n C:Nepal\n D:Lesotho\n Choose your answer from A B C or D\n", 'D'},
  {"Who wrote the novel '1984'?\n A:George Orwell\n B:J.R.R. Tolkien\n C:Mark Twain\n D:Ernest Hemingway\n Choose your answer from A B C or D\n", 'A'},
  {"What is the largest bone in the human body?\n A:Tibia\n B:Femur\n C:Humerus\n D:Skull\n Choose your answer from A B C or D\n", 'B'},
  {"Which planet is the second from the Sun?\n A:Mars\n B:Venus\n C:Earth\n D:Mercury\n Choose your answer from A B C or D\n", 'B'},
  {"What is the name of the phobia that means fear of spiders?\n A:Arachnophobia\n B:Claustrophobia\n C:Agoraphobia\n D:Acrophobia\n Choose your answer from A B C or D\n", 'A'},
  {"Which country has the largest population in the world?\n A:India\n B:China\n C:USA\n D:Indonesia\n Choose your answer from A B C or D\n", 'B'},
  {"Which country has the highest GDP per capita in the world?\n A:Norway\n B:Qatar\n C:Luxembourg\n D:Singapore\n Choose your answer from A B C or D\n", 'B'},
  {"Which country is the smallest by area in the world?\n A:Nauru\n B:Tuvalu\n C:Vatican City\n D:Monaco\n Choose your answer from A B C or D\n", 'C'},
  {"Which country is the only one that has a non-rectangular flag?\n A:Switzerland\n B:Bhutan\n C:Cyprus\n D:Nepal\n Choose your answer from A B C or D\n", 'D'},
  {"Which country is the only one that borders both Canada and Russia?\n A:Mongolia\n B:China\n C:Finland\n D:USA\n Choose your answer from A B C or D\n", 'D'},
  {"Which country has the most spoken languages in the world?\n A:India\n B:Papua New Guinea\n C:China\n D:Nigeria\n Choose your answer from A B C or D\n", 'B'},
  { "Which country is the only one that is also a continent?\n A:Europe\n B:Australia\n C:Antarctica\n D:Africa\n Choose your answer from A B C or D\n", 'B' },
  { "Which country has the longest coastline in the world?\n A:Indonesia\n B:Norway\n C:Canada\n D:Russia\n Choose your answer from A B C or D\n", 'C' },
  { "Which country has the most time zones in the world?\n A:Russia\n B:USA\n C:France\n D:China\n Choose your answer from A B C or D\n", 'C' },
  { "Which country is the largest producer of coffee in the world?\n A:Ethiopia\n B:Brazil\n C:Vietnam\n D:Colombia\n Choose your answer from A B C or D\n", 'B' },
  { "Which country is the birthplace of pizza?\n A:Egypt\n B:China\n C:Italy\n D:Greece\n Choose your answer from A B C or D\n", 'C' },
  { "Which country has the most Nobel laureates in the world?\n A:France\n B:UK\n C:Germany\n D:USA\n Choose your answer from A B C or D\n", 'D' },
  { "Which country is the only one that has a city that spans two continents?\n A:Spain\n B:Russia\n C:Egypt\n D:Turkey\n Choose your answer from A B C or D\n", 'D' },
  { "Which country is the only one that has English as its official language but not its most spoken language?\n A:Australia\n B:India\n C:Nigeria\n D:Ireland\n Choose your answer from A B C or D\n", 'D' },
  { "What is the capital city of Australia?\n A:Sydney\n B:Melbourne\n C:Canberra\n D:Perth\n Choose your answer from A B C or D\n", 'C' },
  { "What is the highest mountain in Africa?\n A:Mount Everest\n B:Mount Kilimanjaro\n C:Mount Aconcagua\n D:Mount McKinley\n Choose your answer from A B C or D\n", 'B' },
  { "What is the largest planet in our solar system?\n A:Venus\n B:Jupiter\n C:Saturn\n D:Mars\n Choose your answer from A B C or D\n", 'B' },
  { "What is the smallest country in the world?\n A:Vatican City\n B:Monaco\n C:San Marino\n D:Liechtenstein\n Choose your answer from A B C or D\n", 'A' },
  { "What is the currency of Japan?\n A:Yuan\n B:Euro\n C:Yen\n D:Pound\n Choose your answer from A B C or D\n", 'C' },
  { "What is the largest ocean in the world?\n A:Arctic Ocean\n B:Indian Ocean\n C:Atlantic Ocean\n D:Pacific Ocean\n Choose your answer from A B C or D\n", 'D' },
  { "What is the world's deepest ocean trench?\n A:Sunda Trench\n B:Puerto Rico Trench\n C:Mariana Trench\n D:Diamantina Trench\n Choose your answer from A B C or D\n", 'C' },
  { "What is the smallest bone in the human body?\n A:Stapes bone in the ear\n B:Femur bone in the leg\n C:Humerus bone in the arm\n D:Vertebrae in the spine\n Choose your answer from A B C or D\n", 'A' },
  { "What is the largest animal on earth?\n A:Elephant\n B:Blue Whale\n C:Giraffe\n D:Hippopotamus\n Choose your answer from A B C or D\n", 'B' },
  { "What is the fastest land animal in the world?\n A:Gazelle\n B:Jaguar\n C:Cheetah\n D:Leopard\n Choose your answer from A B C or D\n", 'C' },
  { "Which of the following is NOT a type of cloud?\n A:Cumulus\n B:Stratus\n C:Cirrus\n D:Kelvin\n Choose your answer from A B C or D\n", 'D' },
  { "What was the name of the first artificial satellite launched into space?\n A:Sputnik 1\n B:Explorer 1\n C:Vanguard 1\n D:Tiros 1\n Choose your answer from A B C or D\n", 'A' },
  { "Who was the first president of the United States?\n A:Thomas Jefferson\n B:George Washington\n C:John Adams\n D:Abraham Lincoln\n Choose your answer from A B C or D\n", 'B' },
  { "What is the capital of Australia?\n A:Sydney\n B:Melbourne\n C:Brisbane\n D:Canberra\n Choose your answer from A B C or D\n", 'D' },
  { "Which of the following animals is NOT a mammal?\n A:Whale\n B:Dolphin\n C:Octopus\n D:Elephant\n Choose your answer from A B C or D\n", 'C' },
  { "What is the name of the highest mountain in the solar system?\n A:Mount Everest\n B:Olympus Mons\n C:Mauna Kea\n D:Mount Kilimanjaro\n Choose your answer from A B C or D\n", 'B' },
  { "Which of the following is the smallest country in the world by land area?\n A:Vatican City\n B:Monaco\n C:San Marino\n D:Nauru\n Choose your answer from A B C or D\n", 'A' },
  { "Who painted the famous artwork 'The Starry Night'?\n A:Pablo Picasso\n B:Vincent van Gogh\n C:Salvador Dalí\n D:Michelangelo\n Choose your answer from A B C or D\n", 'B' },
  { "What is the chemical symbol for gold?\n A:Gd\n B:Ge\n C:G\n D:Au\n Choose your answer from A B C or D\n", 'D' }
};
