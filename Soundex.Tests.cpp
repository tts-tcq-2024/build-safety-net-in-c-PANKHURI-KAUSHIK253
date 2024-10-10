#include <gtest/gtest.h>
#include "Soundex.h"

#define MAX_CODE_LEN 5

char soundex[MAX_CODE_LEN];

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
  generateSoundex("AX", soundex);
 EXPECT_STREQ(soundex,"A200");
 // ASSERT_EQ(soundex,"A200");
}

TEST(SoudexTestsuite, ReplaceLowerCaseToUpeerCaseAndEncode) {
  generateSoundex("kashi", soundex);
 EXPECT_STREQ(soundex,"K200");
}

TEST(SoudexTestsuite, PadsWithZeoIfStringIsLessThanFourCharacters) {
  generateSoundex("kk", soundex);
  EXPECT_STREQ(soundex,"K200");
}

TEST(SoudexTestsuite, HandleEmptyString) {
  generateSoundex("", soundex);
  EXPECT_STREQ(soundex,"");
}

TEST(SoudexTestsuite, IgnoreDuplicateCharactersAndEncod) {
  generateSoundex("FFFF", soundex);
  EXPECT_STREQ(soundex,"F100");
}

TEST(SoudexTestsuite, HandleSpeacialCharacter) {
  generateSoundex("@!%#", soundex);
  EXPECT_STREQ(soundex,"@000");
}

TEST(SoudexTestsuite, ReplaceCharactersByNumbers) {
  generateSoundex("1ABC", soundex);
  EXPECT_STREQ(soundex,"1200");
}

TEST(SoudexTestsuite, IgnoreOtherCharactersIfStringLengthIsMoreThanMaxCodeLength) {
  generateSoundex("abcdefefg", soundex);
  EXPECT_STREQ(soundex,"A123");
}

