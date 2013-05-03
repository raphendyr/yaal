# Define Messages


ifeq ($(LANG), fi)
# Finish
MSG_ERRORS_NONE = Virheitä: ei ollut
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Koko ennen:
MSG_SIZE_AFTER = Koko jälkeen:
MSG_COFF = Muutetaan AVR COFF -muotoon:
MSG_EXTENDED_COFF = Muutetaan AVR Extended COFF -muotoon:
MSG_FLASH = Luodaan lataustiedostoa Flash-osiolle:
MSG_EEPROM = Luodaan lataustiedostao EEPROM-osiolle:
MSG_EXTENDED_LISTING = Luodaan objekti listausta:
MSG_SYMBOL_TABLE = Luodaan symboolitaulua:
MSG_LINKING = Linkataan:
MSG_COMPILING = Käännetään C-koodia:
MSG_COMPILING_CPP = Käännetään C++-koodia:
MSG_ASSEMBLING = Käännetään assemblyä:
MSG_CLEANING = Siivotaan projektia:
MSG_CREATING_LIBRARY = Luodaan kirjastoa:


else
# English
MSG_ERRORS_NONE = Errors: none
MSG_BEGIN = -------- begin --------
MSG_END = --------  end  --------
MSG_SIZE_BEFORE = Size before: 
MSG_SIZE_AFTER = Size after:
MSG_COFF = Converting to AVR COFF:
MSG_EXTENDED_COFF = Converting to AVR Extended COFF:
MSG_FLASH = Creating load file for Flash:
MSG_EEPROM = Creating load file for EEPROM:
MSG_EXTENDED_LISTING = Creating Extended Listing:
MSG_SYMBOL_TABLE = Creating Symbol Table:
MSG_LINKING = Linking:
MSG_COMPILING = Compiling C:
MSG_COMPILING_CPP = Compiling C++:
MSG_ASSEMBLING = Assembling:
MSG_CLEANING = Cleaning project:
MSG_CREATING_LIBRARY = Creating library:


endif
