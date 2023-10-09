-- Keep a log of any SQL queries you execute as you solve the mystery.

-- July 28, 2021 and that it took place on Humphrey Street.
First of all I used "SELECT * FROM crime_scene_reports" to use the hint given by the cs50 course

-- Sorted the table using the WHERE command to see what happened in the exact day
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7;

-- Discovered that Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
Used "SELECT * FROM interviews WHERE day = 28 AND month = 7"; to see the interviews of this day

-- Find ou that the interviews relationed to that crimes were the id:
-- 161 Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- 162 Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- 163 Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- Checked the interviews transcripts and found out there are 2 Eugenes

Used "SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 ORDER BY hour, minute;" to see all license plates of the bakery of that day, based on the interviews too (got it writed down)

-- Checked the Eugenes on people trable to see if there is only one
Used "SELECT name FROM people WHERE name = "Eugene";"

-- Checked the ATM transactions, joined the tables to see the people related to the account numbers and the amount
Used "SELECT account_number, amount FROM atm_transactions WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";"

Used "SELECT name, atm_transactions.amount FROM people
    JOIN bank_accounts
    ON people.id = bank_accounts.person_id
    JOIN atm_transactions
    ON bank_accounts.account_number = atm_transactions.account_number
    WHERE atm_transactions.year = 2021 AND atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.atm_location = 'Leggett Street' AND atm_transactions.transaction_type = "withdraw";"

-- Wrote down those names
-- Started looking for the airport that the witness mentioned about

Used "SELECT abbreviation, full_name, city FROM airports WHERE city = "Fiftyville";"

-- Searched for the flights of july 29
Used "SELECT flights.id, full_name, city, flights.hour, flights.minute FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.origin_airport_id =
       (SELECT id FROM airports WHERE city = "Fiftyville") AND flights.year = 2021 AND flights.month = 7 AND flights.day = 29
 ORDER BY flights.hour, flights.minute;"

 -- As the first flight is to New York City I checked the passanger list of this flight

Used "SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat FROM people
  JOIN passengers
    ON people.passport_number = passengers.passport_number
  JOIN flights
    ON passengers.flight_id = flights.id
 WHERE flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.hour = 8 AND flights.minute = 20 ORDER BY passengers.passport_number;"

-- Wrote down those people names
-- Started to check the people that used phone call tp buy those tickets in less than a minute as the witness told

Used "SELECT name, phone_calls.duration FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;"

 -- Now checking the phone call receiver to see who is the second suspect

 Used "SELECT name, phone_calls.duration FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration <= 60 ORDER BY phone_calls.duration;"

 -- Joined the previous table that I had of the bakery logs changing directly to the name of the people

 Used "SELECT name, bakery_security_logs.hour, bakery_security_logs.minute FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28 AND bakery_security_logs.activity = "exit" AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25 ORDER BY bakery_security_logs.minute;"

-- As Bruce is the only one that appears on the four lists, he is the thief
-- As the first flight was to NYC he must have escaped there
-- As the duration of the call is the same, who helped Bruce was Robin
