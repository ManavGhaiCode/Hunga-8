# SPEC SHEET FOR HUNGA-8

Hunga-8 will be 16-bit computer with a ROM Controller to have more Program Memory.
This means you can't chnage any Program Memory when Hunga-8 is running.

## Instructions

00000: NOP                          -> no operation
00001: LW    reg/imm16              -> DATA BUS = reg/imm16
00010: SW    reg                    -> reg = DATA BUS
00011: LDA                          -> DATA BUS = A
00100: LDB                          -> DATA BUS = B
00101: LDC                          -> DATA BUS = C
00110: STA                          -> A = DATA BUS
00111: STB                          -> B = DATA BUS
01000: AND   reg0, reg1             -> C = reg0 & reg1
01001: OR    reg0, reg1             -> C = reg0 | reg1
01010: NOR   reg0, reg1             -> C = !(reg0 | reg1)
01011: ADD   reg0/imm16, reg1/imm16 -> C = reg0/imm16 + reg1/imm16
01100: SUB   reg0/imm16, reg1/imm16 -> C = reg0/imm16 - reg1/imm16
01101: MLT   reg0/imm16, reg1/imm16 -> C = reg0/imm16 * reg1/imm16
01110: DIV   reg0/imm16, reg1/imm16 -> C = reg0/imm16 / reg1/imm16
01111: CMP   reg0/imm16, reg1/imm16 -> F.EQ/LESS = (reg0/imm16 == reg1/imm16)
10000: PUSH  imm16(addr)            -> [SP++] = addr
10001: POP                          -> [SP--]
10010: JMP   imm16(addr)            -> I = addr
10011: JNZ   reg/imm16, imm16(addr) -> I = (reg/imm16 != 0) ? (HLT : JMP addr)
10100: JMS   imm16(addr)            -> [SP++] = G, JMP addr, [SP++] = G
10101: JOS                          -> [SP--], JMP SP
10110: LEP                          -> DATA BUS = EP
10111: HLT                          -> CLOCK SPEED = 0

## Regesters Layout

A: GP Regester
B: GP Regester
C: Output Regester
G: Address Regester

I: Instruction Regester
	I.D: args0
	I.E: args1

F: (F)lags Regester
	Less
	Equal
	Overflow

SP: (S)tack (P)ointer

## Memory Layout

Pogram Memory   : 128  KB
Computer Memory : 128  KB
Char ROM        : 128  KB

Total: 256KB

### Pogram Memory Layout

0x0000 - 0xFFFF: Program Memory  (BANKED)

Allows for a total of 65536 programs loaded on this computer.
With a total of 16-bits to for setting Bank Number.

### Computer Memory Layout

0x0000...0x3FFF: GP ROM Memory        -> 32   KB  (BANKED)
0x4000...0xBFFF: GP RAM Memory        -> 64   KB
0xC000...0xC4FF: Stack Memory         -> 2.5  KB
0xC500...0xC5FF: Video Memory         -> 0.5  KB
0xC600...0xFFFB: GP RAM Memory        -> 29   KB
0xFFFC...0xFFFC: Program Bank Number  -> 16   BI
0xFFFD...0xFFFD: GP ROM Bank Number   -> 16   BI
0xFFFE...0xFFFE: Char Bank Number     -> 16   BI
0xFFFF...0xFFFF: (E)xpandtion (P)ort  -> 16   BI

## Frame Data Strage Format

Video Memory is divded into 2:
	-- CM 0xC500...0xC5FF
	-- CR 0x0000...0xFFFF

CM 0xC500 to 0xC5FF is used to store 128 chars of 8x8 sprites.
Each Char is stored over 32bits (2Regs), reg 1 for storing the char number and z-index. reg 2 for storting the data of position.

REG 1:

|----------||------|
10bits      6bits
For Char    For ZI

REG 2:

|--||-------||-------|
2BI   8Bits    8Bits
Nan   X pos    Y pos

According to the char ID the GPU (c++ based) look at a table in the char sheet in Video memory to get the a string of 128bits with tell if a pixel is transparent, Black, White.

The colors are refpersented by 2bit:

00: Black
01: White
10: transparent
11: Unused

EG for a char sheet:

00 00 00 00 00 00 00 00
00 00 00 01 01 00 00 00
00 00 01 00 00 01 00 00
00 00 01 00 00 01 00 00
00 00 01 01 01 01 00 00
00 00 01 00 00 01 00 00
00 00 01 00 00 01 00 00
00 00 01 00 00 01 00 00

This is a char sheet for A.