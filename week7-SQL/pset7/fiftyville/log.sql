-- Keep a log of any SQL queries you execute as you solve the mystery.


-- Month: July (7)| Day: 28th | 2023 | Theft: 10:15am | bakery | Littering took place at 16:36 | Three witnesses


-- All I got so far is: month, day and street. With that, I can look through crime reports' description of that date
SELECT description
FROM crime_scene_reports
WHERE month = 7 and day = 28
AND street = 'Humphrey Street';

-- Check more about the three witnesses interviews to find out more information
SELECT transcript 
FROM interviews 
WHERE month = 7 AND day = 28;


-- Early in that morning the thief was withdrawing money from ATM on Leggett Street. -> check atm_transactions, bank_accounts
SELECT * 
FROM atm_transactions 
WHERE month = 7 AND day = 28 
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- As I got the account numbers from anyone that withdrawed money on that morning, it's time to find the names
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 28500762; -- Luca: 48    
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 28296815; -- Kenny: 20   
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 76054385; -- Taylor: 60     
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 49610011; -- Bruce: 50   
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 16153065; -- Brooke: 80  
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 25506511; -- Iman: 20    
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 81061156; -- Benista: 30 
SELECT name FROM people JOIN bank_accounts ON bank_accounts.person_id = people.id WHERE bank_accounts.account_number = 26013199; -- Diana: 35  

-- around 10:25am thief entered  a car that was parked -> check bakery security footage to find licanse plates from everyone that exited the parking lot around 10:15 to 10:30
SELECT * 
from bakery_security_logs
WHERE month = 7 AND day = 28
AND hour = 10 AND minute < 30 
AND activity = 'exit';

-- Check to whom the license plates belongs
SELECT name, phone_number, passport_number from people WHERE license_plate = '0NTHK55'; -- Kelsey (number: (499) 555-9472 | passport: 8294398571) 
SELECT name, phone_number, passport_number from people WHERE license_plate = '322W7JE'; -- 10:23 - Diana (number:(770) 555-1861 | passport: 3592750733)   (suspect)
SELECT name, phone_number, passport_number from people WHERE license_plate = 'L93JTIZ'; -- 10:21 - Iman (number: (829) 555-5269 | passport: 7049073643)   (suspect)
SELECT name, phone_number, passport_number from people WHERE license_plate = 'G412CB7'; -- Sofia (number: (130) 555-0289 | passport: 1695452385)  
SELECT name, phone_number, passport_number from people WHERE license_plate = '4328GD8'; -- 10:19 - Luca (numer: (389) 555-5198 | passport: 8496433585)    (suspect)
SELECT name, phone_number, passport_number from people WHERE license_plate = '6P58WS2'; -- Barry                                                  
SELECT name, phone_number, passport_number from people WHERE license_plate = '94KL13X'; -- 10:18 - Bruce (number: (367) 555-5533 | passport: 5773159633)  (suspect)


-- Right when he was leaving, the thief called someone to buy plane tickets for him to the earliest plane on the next day. Check if suspects called someone
SELECT * from phone_calls WHERE month = 7 AND day = 28 AND caller = '(499) 555-9472'; -- Diana (suspect) -- (892) 555-8872) and (717) 555-1342
SELECT * from phone_calls WHERE month = 7 AND day = 28 AND caller = '(367) 555-5533'; -- Bruce (suspect) -- (375) 555-8161, (344) 555-9601, (022) 555-4052 and (704) 555-5790
SELECT * from phone_calls WHERE month = 7 AND day = 28 AND caller = '(829) 555-5269'; -- Iman (0 calls)
SELECT * from phone_calls WHERE month = 7 AND day = 28 AND caller = '(389) 555-5198'; -- Luca (0 calls)

-- Checing the earliest flights on the next day
SELECT * from flights where month = 7 and day = 29 ORDER BY hour, minute; -- 5 flights total: ids: 36, 43, 23, 53 and 18

-- Checking passangers on each flight
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.id = 36; --BRUCES PASSPORT FOUND HERE
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.id = 43;
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.id = 23;
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.id = 53;
SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id JOIN people ON passengers.passport_number = people.passport_number WHERE flights.id = 18; -- DIANAS PASSPORT FOUND HERE

-- Check where did the thief go
SELECT *
FROM airports
LEFT JOIN flights ON flights.destination_airport_id = airports.id
WHERE flights.destination_airport_id = 4
AND month = 7 AND day = 28
ORDER BY id;

-- Check numbers Bruce called
SELECT * from phone_calls WHERE month = 7 AND day = 28 AND caller = '(367) 555-5533' --He did 4 calls, but just one of them was less than 60s, receiver: (375) 555-8161

-- Check who the receiver is
SELECT name
FROM people
JOIN phone_calls ON phone_calls.receiver = people.phone_number
WHERE month = 7 AND day = 28 
AND duration < 60
AND phone_calls.receiver = '(375) 555-8161';