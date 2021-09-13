#include "questiondealer.h"

QuestionDealer::QuestionDealer()
{
    Question* question;

    //Math
    question = new Question("What is 2+2",
                            "5", "6", "4", "1",
                            3, 30, 0);
    mathQuestions.append(question);
    question = new Question("What is the square root of 256?",
                            "16", "14", "18", "11",
                            1, 120, 0);
    mathQuestions.append(question);
    question = new Question("67*31?",
                            "2891", "1862", "2077", "2020",
                            3, 200, 0);
    mathQuestions.append(question);
    question = new Question("What is the prime number after 7",
                            "9", "7", "15", "11",
                            4, 80, 0);
    mathQuestions.append(question);
    question = new Question("Continue this pattern: 144, 121, 100, 81, 64, ",
                            "49", "55", "31", "5",
                            1, 120, 0);
    mathQuestions.append(question);
    question = new Question("What is the sum of the angles of a triangle?",
                            "120", "0", "90", "180",
                            4, 100, 0);
    mathQuestions.append(question);
    question = new Question("Subtract 457 from 832",
                            "375", "57", "376", "970",
                            1, 200, 0);
    mathQuestions.append(question);
    question = new Question("50 times 5 is equal to",
                            "505", "2500", "250", "500",
                            3, 110, 0);
    mathQuestions.append(question);
    question = new Question("What general shape does a second degree equation have",
                            "Line", "Circle", "None", "Parabola",
                            4, 100, 0);
    mathQuestions.append(question);
    question = new Question("When given a relatively basic quadratic question such as  \nx^2 + 9x + 20, which of these options is a suitable way to solve it?",
                            "Factorising", "Derivatising", "Collaborating", "Collating",
                            1, 150, 0);
    mathQuestions.append(question);
    question = new Question("What would be the two constituents of the following quadratic \nequation: x^2 + x - 6?",
                            "(x+6) and (x+5)", "(x+4) and (x+4)", "(x+3) and (x-2)", "(x+3) and (x+2)",
                            3, 140, 0);
    mathQuestions.append(question);
    question = new Question("What is the formula for the Pythagorean Theorem?",
                            "a^2 + b^2 = c", "a + b = c^2", "a^2 + b^2 = c^2", "(a + b)^2",
                            3, 90, 0);
    mathQuestions.append(question);
    question = new Question("If you have a right triangle with shorter side lengths a = 3 and b = 4; \nwhat will the hypotenuse, c, equal?",
                            "5", "25", "7", "none of these",
                            1, 140, 0);
    mathQuestions.append(question);
    question = new Question("If you have a right triangle with short side length a = 5 \nand hypotenuse length c = 13, what is the value of side length b?",
                            "18", "none of these", "144", "12",
                            4, 140, 0);
    mathQuestions.append(question);
    question = new Question("If two straight lines are drawn from either end of the diameter \nof a circle and meet at a point on the circumference, what will the angle always be?",
                            "70 degrees", "45 degrees", "90 degrees", "30 degrees",
                            3, 110, 0);
    mathQuestions.append(question);
    question = new Question("What is the geometric name given to a straight line which \ntouches the circumference of a circle at one point only?",
                            "Tangent", "Cosine", "Sine", "Sinco",
                            1, 110, 0);
    mathQuestions.append(question);
    question = new Question("When a straight line touching a circle in exactly one point \nmeets the radius or diameter of a circle, what is the size of the angle always formed?",
                            "90 degrees", "30 degrees", "45 degrees", "70 degrees",
                            1, 120, 0);
    mathQuestions.append(question);
    question = new Question("When a four-sided shape, where each corner touches the circumference \nis found inside a circle, it is called a cyclic quadrilateral. What is the rule about the size of the angles that are opposite to each other?",
                            "They total 90 degrees", "They total 135 degrees", "They total 45 degrees", "They total 180 degrees",
                            4, 110, 0);
    mathQuestions.append(question);
    question = new Question("Which of the following statements is true of isosceles triangles?",
                            "Two of the angles are equal", "Two of the sides are equal", "None of these", "Both of these",
                            4, 100, 0);
    mathQuestions.append(question);
    question = new Question("Rare event!!!\nIt only happens once a year!!!\nIt's christmas!!!!!!!!!",
                            "I want the 300$!", "I'm better than this, keep yer money", "Don't select this answere", "This one neither",
                            1, 300, 0);
    mathQuestions.append(question);

    //history
    question = new Question("Constantine the Great was the first Emperor who based his reign in Constantinople (formerly known as Byzantium). \nWhich of his sons did *NOT* succeed him in any part of the Empire? ",
                            "Constantius II", "Constantine II", "Crispus", "Constans",
                            3, 200, 2);
    historyQuestions.append(question);
    question = new Question("In 457 Leo I the Thracian ascended to the throne, the first of the Leonid dynasty. \nWhere was he born?  ",
                            "On the Byzantine throne", "Exactly the same spot where he would later die", "Dacia", "At sea",
                            3, 200, 2);
    historyQuestions.append(question);
    question = new Question("The last Byzantine Emperor from the Justinian dynasty had a name \nwe don't usually associate with Roman or Byzantine rulers. \nWhat was his name? ",
                            "Jean", "Roald", "Maurice", "Jacob",
                            3, 180, 2);
    historyQuestions.append(question);
    question = new Question("One of the most recognizable of the Byzantine Emperors would certainly be Justinian II Rhinotmetos, \nEmperor between 685 and 695 and once again from 705 until 711. \nWhat was striking about his appearance?",
                            "He was more than 2 meters tall.", "His beard was a fierce red colour", "He went everywhere dressed only in a loincloth.", "His nose was cut off. ",
                            4, 170, 2);
    historyQuestions.append(question);
    question = new Question("What was the main focus of the internal politics of the Isaurian dynasty (717-802)?",
                            "Conservation of scientific literatureI", "Religious icons", "Codification of civil law", "Silk industry",
                            4, 140, 2);
    historyQuestions.append(question);
    question = new Question("In 802 a logothete (major official) became Emperor. \nHis son Staurakios would succeed him in 811 for a few months, \nthen followed by the logothete's son-in-law Michael I. \nWho was this logothete, who (according to his name) would have brought victory?",
                            "Theophilos", "Nikephoros I", "Philippikos", "Andronikos I",
                            2, 180, 2);
    historyQuestions.append(question);
    question = new Question("Which dynasty ruled Byzantium between 867 and 1056? \nIt was named after the place of birth of its founder Basil I.",
                            "Valentinian dynasty", "Macedonian dynasty", "Theodosian dynasty", "Constantine dynasty",
                            2, 130, 2);
    historyQuestions.append(question);
    question = new Question("Which Byzantine Emperor was wounded at the battle of Manzikert in 1071? \nHe didn't live in a barrel, though.",
                            "Andronikos II Palaiologos", "Michael VI Bringas ho Geron", "Romanos IV Diogenes", "Isaac II Angelos",
                            3, 190, 2);
    historyQuestions.append(question);
    question = new Question("Who was the byzantine Emperor with the longest continuous reign?",
                            "Basil II Bulgaroktonos", "Constantine VII Porphyrogenetos", "Andronikos II Palaiologos", "Theodosius",
                            1, 140, 2);
    historyQuestions.append(question);
    question = new Question("Which country was NOT considered a Viking homeland?",
                            "Sweden", "Finland", "Denmark", "Norway",
                            2, 100, 2);
    historyQuestions.append(question);
    question = new Question("Before the use of coins in the Viking world, \nwhat method of payment was common?",
                            "amber", "iron bars", "hack silver", "carved bone",
                            3, 110, 2);
    historyQuestions.append(question);
    question = new Question("There is very little recorded history of Vikings in Russia. \nWhat evidence of their presence did the Vikings leave behind?",
                            "all of these", "runic inscriptions", "weapons", "brooches",
                            1, 90, 2);
    historyQuestions.append(question);
    question = new Question("What was the treasure a Viking was buried with called?",
                            "grave goods", "Thor's plunder", "death bounty", "Viking hoard",
                            1, 85, 2);
    historyQuestions.append(question);
    question = new Question("What were Vikings NOT known as?",
                            "explorers", "craftsmen", "missionaries", "traders",
                            3, 100, 2);
    historyQuestions.append(question);
    question = new Question("Thor was the Norse god of Thunder. \nWhat symbol of Thor did Vikings wear as jewelry?",
                            "ram's horn", "snake", "Thor's hammer", "lightning bolt",
                            3, 70, 2);
    historyQuestions.append(question);
    question = new Question("What were Viking weapons made of?",
                            "iron", "bone", "copper", "wood",
                            1, 90, 2);
    historyQuestions.append(question);
    question = new Question("What use did the Vikings have for walrus skins?",
                            "clothing", "ship rope", "tarps", "shoes",
                            2, 150, 2);
    historyQuestions.append(question);
    question = new Question("A pair of oval brooches are found within an excavated Viking Age grave site. \nWho was buried there?",
                            "a child", "a woman", "a man", "a member of royalty",
                            2, 130, 2);
    historyQuestions.append(question);
    question = new Question("A thrall was a slave during the Viking Age. How did a person become a thrall?",
                            "being born to a thrall mother", "voluntarily becoming a thrall", "capture", "all of these",
                            4, 140, 2);
    historyQuestions.append(question);
    question = new Question("What exactly was a 'motte'?",
                            "Flaky apple dessert dusted with nutmeg", "Slogan on the Lord's family crest", "Mound a castle was built on", "A beauty patch used by Ladies",
                            3, 160, 2);
    historyQuestions.append(question);
    question = new Question("What do you think a 'quintain' was?",
                            "Dummy used in jousting practice", "Traditional style of 8-lined verse", "A popular dance with many intricate steps", "Type of tonic used to treat fevers",
                            1, 160, 2);
    historyQuestions.append(question);
    question = new Question("To get out of military service, \nwhat did a vassal pay to his lord?",
                            "An allure", "A scutage", "Heriot", "Alms",
                            2, 170, 2);
    historyQuestions.append(question);
    question = new Question("What do you think a 'sackbut' could have been?",
                            "Belt with tassels that a Lady wore around her hips", "Medieval instrument akin to the trombone", "Mulled wine heated with a hot poker", "A bag that ground millet was stored in",
                            2, 155, 2);
    historyQuestions.append(question);
    question = new Question("A 'buttery' is best described by which of the following?",
                            "Container lowered into the castle well to keep dairy products cool", "Puff pastry layered with almond paste", "Room used for the serving of beer and wine", "Cook's helper who basted roasting meats",
                            3, 150, 2);
    historyQuestions.append(question);
    question = new Question("What do you think a 'trebuchet' was?",
                            "Tipped lance used in jousting practice", "Thick slice of day old bread used as a meat plate", "Iron hook used to suspend cooking pots over the fire", "War engine used to hurl heavy missiles",
                            4, 100, 2);
    historyQuestions.append(question);
    question = new Question("Bern became the federal capital of Switzerland in 1848. \nWhen was it originally founded?",
                            "1847", "415", "1752", "1191",
                            4, 120, 2);
    historyQuestions.append(question);
    question = new Question("In 1506, a special group of military men were appointed to protect the Pope. \nEven 500 years later, this group of men still served to protect (well, not the exact same men ... They're dead). \nWhat is the group called?",
                            "Swiss Army", "Swiss Papal Protection", "Swiss Service", "Swiss Guard",
                            4, 110, 2);
    historyQuestions.append(question);
    question = new Question("The Reformation in Switzerland took place in the 16th century. \nWho led the Reformation?",
                            "Jorg Jenatsch", "Huldrych Zwingli", "Johann Rudolf Wettstein", "Leonard Euler",
                            2, 190, 2);
    historyQuestions.append(question);
    question = new Question("In 1712, the second battle of Villmergen took place. \nBy what other name was it known?",
                            "Morgarten War", "Sempach War", "Sonderbund War", "Toggenburg War",
                            4, 210, 2);
    historyQuestions.append(question);
    question = new Question("In 1963, Switzerland joined which of these organizations?",
                            "European Union", "European Council", "United Nations", "Council of Europe",
                            4, 115, 2);
    historyQuestions.append(question);
    question = new Question("During which war did the Battle of Marignano take place?",
                            "French-Indian Wars", "Sino-Japanese War", "World War II", "Italian Wars",
                            4, 160, 2);
    historyQuestions.append(question);
    question = new Question("In 1648, Switzerland gained internationally recognized independence from the Holy Roman Empire. \nUnder which treaty were they given independence?",
                            "Treaty of Augsburg", "Treaty of Versailles", "Treaty of Westphalia", "Treaty of Paris",
                            3, 215, 2);
    historyQuestions.append(question);
    question = new Question("In 1798, France took over Switzerland, and renamed it. \nWhat was the new republic called?",
                            "Helmet Republic", "Hellbent Republic", "Hellenistic Republic", "Helvetic Republic",
                            4, 90, 2);
    historyQuestions.append(question);
    question = new Question("Switzerland regained full independence in 1815. \nWhich of these gave Switzerland independence, and also recognized Switzerland as a neutral country?",
                            "Congress of Venice", "Congress of Copenhagen", "Congress of Vienna", "Congress of Geneva",
                            3, 160, 2);
    historyQuestions.append(question);
    question = new Question("Switzerland was founded exactly one hundred years after its capital city, Bern, was founded. \nIn what year was Switzerland originally founded?",
                            "515", "1947", "1291", "1852",
                            3, 170, 2);
    historyQuestions.append(question);
    question = new Question("Rare event!!!\nIt only happens once a year!!!\nIt's christmas!!!!!!!!!",
                            "I want the 300$!", "I'm better than this, keep yer money", "Don't select this answere", "This one neither",
                            1, 300, 2);
    historyQuestions.append(question);




//    question = new Question("QQQQQQQ",
//                            "AAA", "BBB", "CCC", "DDD",
//                            1, 150, 2);
//    historyQuestions.append(question);



    //physique
    question = new Question("When was Isaac Newton born?",
                            "1783", "Despite making 13% of the population, ...", "1666", "1642",
                            3, 170, 1);
    physicQuestions.append(question);
    question = new Question("The instrument tht measures and records the relative humidity of air is",
                            "Hydrometer", "Hygrometer", "Lactometer", "Barometer",
                            2, 165, 1);
    physicQuestions.append(question);
    question = new Question("The shape of our milky way galaxy is",
                            "Circular", "Eliptical", "Spiral", "None of the above",
                            3, 90, 1);
    physicQuestions.append(question);
    question = new Question("The different colors of different stars are due to the variation of",
                            "Temperature", "Pressure", "Density", "Radiation from them",
                            1, 105, 1);
    physicQuestions.append(question);
    question = new Question("The fundemental scientific principle in the operation of battery is",
                            "Acid-base interraction", "Dialysis", "Dissociation of electrolytes", "Oxidation-reduction",
                            3, 140, 1);
    physicQuestions.append(question);
    question = new Question("Instrument used to mesure the force and velocity of the wind is",
                            "Ammeter", "Anemometer", "Altimeter", "Audiometer",
                            2, 140, 1);
    physicQuestions.append(question);
    question = new Question("Woolen clothes keeps the body warm because",
                            "Wool increase the temperature of the body", "Wool is a bad conductor", "Wool absorbs radiant heat from outer objects", "Wool rejects heat from outer objects",
                            2, 110, 1);
    physicQuestions.append(question);
    question = new Question("If the length of a simple pendulum is halved then its period of oscillation is",
                            "doubled", "Halved", "Increased by a factor", "Decreased by a factor",
                            4, 170, 1);
    physicQuestions.append(question);
    question = new Question("Geostationary satellite revolves at",
                            "Any Height", "Fixed height", "Height wich depends upon its mass", "Height above pole",
                            2, 100, 1);
    physicQuestions.append(question);
    question = new Question("Asteroids revolve around the sun between wich of the following planets",
                            "Earth and Mars", "Mars and Jupiter", "Jupiter and Saturn", "Saturn and Uranus",
                            2, 130, 1);
    physicQuestions.append(question);
    question = new Question("The speed of light with the rise in the temperature of the medium",
                            "Increases", "Decreases", "Remains unaltered", "Drops suddenly",
                            3, 135, 1);
    physicQuestions.append(question);
    question = new Question("Clothes keeps us warm in winter because they",
                            "Supply heat", "Do not radiate heat", "Prevent air from contacting the body", "Prevent the heat of the body from escaping",
                            4, 100, 1);
    physicQuestions.append(question);
    question = new Question("Which of the following is an example of a second class lever?",
                            "Ice tongs", "Shovels", "Scissors ", "Nut cracker",
                            4, 125, 1);
    physicQuestions.append(question);
    question = new Question("Which of the these is the SI unit of the physical quantity \nwhich defines the rate of doing work?",
                            "Kilowatt hour", "Joule", "Watt", "Kelvin",
                            3, 110, 1);
    physicQuestions.append(question);
    question = new Question("Who is credited with the discovery of infrared radiation?",
                            "William Herschel", "Paul Villard", "Johann Ritter", "Daniel Gabriel",
                            1, 210, 1);
    physicQuestions.append(question);
    question = new Question("Which of these is an example of a paramagnetic element?",
                            "Platinum", "Gold", "Silver", "Copper",
                            1, 200, 1);
    physicQuestions.append(question);
    question = new Question("Who discovered the photoelectric effect in 1887?",
                            "Albert Einstein", "Heinrich Rudolf Hertz", "Nicola Tesla", "Benjamin Franklin",
                            2, 215, 1);
    physicQuestions.append(question);
    question = new Question("CDs reflect rainbow colours when exposed to light. \nWhich phenomenon of light is responsible for this?",
                            "Polarisation", "Interference", "Scattering", "Dispersion",
                            2, 180, 1);
    physicQuestions.append(question);
    question = new Question("Which of the following is not a type of diode?",
                            "Steep", "Zener", "Tunnel", "Gunn",
                            1, 220, 1);
    physicQuestions.append(question);
    question = new Question("Which of the following particles is found in the nucleus of an atom?",
                            "Electron", "Proton", "Photon", "Positron",
                            2, 120, 1);
    physicQuestions.append(question);
    question = new Question("Which of the following is a unit of astronomical distance?",
                            "Siriometer", "Houndometer", "Googolometer", "Bixbometer",
                            1, 200, 1);
    physicQuestions.append(question);
    question = new Question("If the displacement of an object is zero, then which of the following can be different than zero?",
                            "Average velocity of the object", "Average work done by the object", "Average acceleration of the object", "Distance travelled by the object",
                            4, 160, 1);
    physicQuestions.append(question);
    question = new Question("Rare event!!!\nIt only happens once a year!!!\nIt's christmas!!!!!!!!!",
                            "I want the 300$!", "I'm better than this, keep yer money", "Don't select this answere", "This one neither",
                            1, 300, 1);
    physicQuestions.append(question);
}

Question* QuestionDealer::getQuestion(int category)
{
    int m;
    Question* q;
    switch (category)
    {
        case 0:
        {
            m = QRandomGenerator::global()->bounded(mathQuestions.size());
            q = mathQuestions[m];
            break;
        }
        case 1:
        {
            m = QRandomGenerator::global()->bounded(physicQuestions.size());
            q = physicQuestions[m];
            break;
        }
        case 2:
        {
            m = QRandomGenerator::global()->bounded(historyQuestions.size());
            q = historyQuestions[m];
            break;
        }

    }
    return q;
}
