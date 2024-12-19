//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#ifndef VALVECDKEYGAMEANDTERRITORYCODES_H
#define VALVECDKEYGAMEANDTERRITORYCODES_H
#ifdef _WIN32
#pragma once
#endif

// imported from
// MainIntegration/Deliverables/Production/Client/Inc/NewValveCDKeyGenerator.h
// if the enums there change, this needs to change
//!! these need to be moved out into a seperate file in steam, so that src can
//!use the directly published version

//
// GameCode
//

enum EGameCode {
  // DoD uses SteamInstanceId = 1
  // DoD CD-key Steam IDs are displayed as VALVE_1:xxxxxxxx where xxxx is the
  // SteamLocalUserId mentioned above. DoD CD-keys uses an odd scheme (invented
  // in a rush) whereby the SteamLocalUserID is generated by hashing (MD5) the
  // CD key parameters (Territory,GameCode,UniqueSerialNumber) and truncating
  // the resulting hash for a reasonable display length (26 bits, i.e.
  // eMaskLargestAcceptableLocalUserId above, which is about 8 decimal digits).
  // **The generator must therefore discard any UniqueSerialNumbers that cause
  // hashes to collide.** This means that when generating a new batch from a
  // non-zero StartUniqueSerialNumber, the generator has to generate them all
  // from 0 anyway to populate an array of 'hash has been used' flags -- it then
  // only prints out new keys higher than the requested StartUniqueSerialNumber.
  // IMPORTANT: this means that each match of N keys generated consumes MORE
  // THAN N UniqueSerialNumbers -- so each new batch MUST be started with the
  // correct "Next StartUniqueSerialNumber" that was output at the end of the
  // previous batch, or the new batch will overlap with the previous batch.
  eDayOfDefeat = 0,

  // CZ uses SteamInstanceId = 2 (**as will all future games using this
  // system**) CZ CD-key SteamLocalUserIds have
  //				high32bits	= ( GameCode <<
  //sc_uNumBitsSalesTerritory) | SalesTerritory 				low32bits	=
  //UniqueSerialNumber
  // CZ CD-key Steam IDs will be displayed as
  // VALVE_2:GameCode:UniqueSerialNumber (i.e. the DoD hashing scheme is *NOT*
  // used).
  eConditionZero = 1,

  // CyberCafes receive all legacy and future products, under this one code.
  // They have their own SalesTerritory codes too.
  // If a CDKey has this game code OR a CyberCafe SalesTerritory then it is a
  // 'cybercafe CDkey'.
  eCyberCafeBundle = 2,

  eHalfLife2 = 3,

  eHalfLife2RetailCE = 4,

  eHalfLife2Retail = 5,
};

//
// SalesTerritory
//

enum ESalesTerritory {
  // DoD				first batch		 80,000	keys
  // **Next free 'StartUniqueSerialNumber' =  80032 DoD
  // second batch	 30,000	keys	**Next free 'StartUniqueSerialNumber' =
  // 110081 OLD KEY		... NOTE: this CZ first batch for USA (code 0)
  // of 275,000 may also be distributed in Canada OLD KEY		... i.e.
  // they should ideally have had code 11, but we didn't want to re-issue them.
  // OLD KEY		ConditionZero	first batch		275,000 keys
  // **Next free 'StartUniqueSerialNumber' = 275000 NEW KEY	These were moved
  // to region 11 as suggested above (part of first batch of 379,000)
  eUSA = 0,

  // DoD				first batch		  7,500	keys
  // **Next free 'StartUniqueSerialNumber' = 7500
  eAustralia = 1,

  // DoD				first batch		 15,000	keys
  // **Next free 'StartUniqueSerialNumber' = 15000
  eKorea = 2,

  // DoD				first batch		 10,000	keys
  // **Next free 'StartUniqueSerialNumber' = 10000
  eTaiwan = 3,

  // DoD				first batch		  5,000	keys
  // **Next free 'StartUniqueSerialNumber' = 5000
  eJapan = 4,

  // DoD				first batch		 25,000 keys
  // **Next free 'StartUniqueSerialNumber' = 25003 ConditionZero	first
  // batch		 99,000 keys	**Next free 'StartUniqueSerialNumber' =
  // 99000
  eUK = 5,

  // DoD				first batch		 15,000 keys
  // **Next free 'StartUniqueSerialNumber' = 15002 ConditionZero	first
  // batch		 77,000 keys	**Next free 'StartUniqueSerialNumber' =
  // 77000
  eFrance = 6,

  // DoD				first batch		  3,000 keys
  // **Next free 'StartUniqueSerialNumber' = 3000 DoD
  // second batch	  5,000 keys	**Next free 'StartUniqueSerialNumber' =
  // 8002 ConditionZero	first batch		132,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 132000
  eGermany = 7,

  // DoD				first batch		  3,000 keys
  // **Next free 'StartUniqueSerialNumber' = 3000 ConditionZero	first batch
  // 27,500 keys	**Next free 'StartUniqueSerialNumber' = 27500
  eSpain = 8,

  // DoD				first batch		  3,000 keys
  // **Next free 'StartUniqueSerialNumber' = 3000 ConditionZero	first batch
  // 44,000 keys	**Next free 'StartUniqueSerialNumber' = 44000
  eItaly = 9,

  // DoD				first batch		 65,000 keys
  // **Next free 'StartUniqueSerialNumber' = 65039 DoD
  // second batch	 20,000 keys	**Next free 'StartUniqueSerialNumber' =
  // 85058
  eChina = 10,

  // This is ALL 'American' ENGLISH-SPEAKING TERRITORIES (e.g. USA, Austrailia,
  // Canada, NZ, but *NOT* UK). Vivendi track sales by language, rather that
  // geographically. OLD KEY	... NOTE: CZ first batch for USA (code 0) of
  // 275,000 will also be distributed in these territories OLD KEY	... i.e.
  // they should ideally have had this code, but we didn't want to re-issue
  // them. OLD KEY		ConditionZero	first batch		 25,000
  // keys	**Next free 'StartUniqueSerialNumber' = 25000 OLD KEY
  // ConditionZero	second batch	 79,000	keys	**Next free
  // 'StartUniqueSerialNumber' = 104000 NEW KEY ConditionZero	first batch
  // 379,000	keys	**Next free 'StartUniqueSerialNumber' =
  eEnglish = 11,

  // CyberCafe specific territories. If a CDKey has this game code OR a
  // CyberCafe SalesTerritory then it is a 'cybercafe CDkey'. CyberCafeBundle
  // first batch		 15,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 15000
  eCyberCafeEurope = 12,
  // CyberCafeBundle	first batch		 15,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 15000
  eCyberCafeNorthAndSouthAmerica = 13,
  // CyberCafeBundle	first batch		 15,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 15000
  eCyberCafeKorea = 14,
  // CyberCafeBundle	first batch		 15,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 15000
  eCyberCafeChinaTaiwan = 15,
  // CyberCafeBundle	first batch		 15,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 15000
  eCyberCafeRestOfAsia = 16,

  // ATI OEM
  // *** After intranet security breach, only the first 40,000 of these keys are
  // valid: OLD KEY	HL2				first batch
  // 250,000 keys
  // *** After intranet security breach, these keys use a new MAC key:
  // NEW KEY	HL2				first batch	    start=40,000
  // 210,000 keys
  eATI_OEM = 17,

  // ConditionZero	first batch		  5,500 keys	**Next free
  // 'StartUniqueSerialNumber' = 5500
  eLatinAmerica = 18,

  // ConditionZero	first batch		 16,500 keys	**Next free
  // 'StartUniqueSerialNumber' = 16500
  eBrazil = 19,

  // ConditionZero	first batch		 66,000 keys	**Next free
  // 'StartUniqueSerialNumber' = 66000
  eNordic = 20,

  // This a Vivendi code meaning "Belgium, Luxembourg, French speaking
  // territories of Africa, French overseas departments, Netherlands, Quebec"
  // ConditionZero	first batch		 40,700 keys	**Next free
  // 'StartUniqueSerialNumber' = 40700
  eExportFrance = 21,

  // This a Vivendi code meaning "Austria, Switzerland, Bulgaria, Czech
  // Republic, Hungary, Lithuania, Poland, Romania, Russian Federation,
  // Slovenia, Slovakia" ConditionZero	first batch		 16,500 keys
  // **Next free 'StartUniqueSerialNumber' = 16500
  eExportNorth = 22,

  // This a Vivendi code meaning "Cyprus, Egypt, Greece, Israel, Lebanon, Malta,
  // Turkey" ConditionZero	first batch		 40,700 keys	**Next
  // free 'StartUniqueSerialNumber' = 40700
  eExportSouth = 23,

  // MISSING ONES ARE ON MI (24..29)

  // ATI Rebate
  // HL2				first batch	    100,000 keys
  eATI_Rebate = 30,

  // Used for internal and pre-release testing keys.
  // DoD				first batch		     20 keys
  // **Next free 'StartUniqueSerialNumber' = 20 DoD
  // second batch	    150 keys	**Next free 'StartUniqueSerialNumber' =
  // 170 DoD				second batch	    500 keys	**Next
  // free 'StartUniqueSerialNumber' = 670 ConditionZero	first batch
  // 200 keys	**Next free 'StartUniqueSerialNumber' = 200 CyberCafeBundle
  // first batch		    100 keys	**Next free
  // 'StartUniqueSerialNumber' = 100
  eInternal = 255
};

#endif // VALVECDKEYGAMEANDTERRITORYCODES_H
