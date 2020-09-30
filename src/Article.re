[@react.component]
let make = (~link, ~title, ~aid) => {

    <div>
        <a
            className="block mb-10 text-center font-bold text-2xl"
            rel="noopener noreferrer"
            href=link
        >
            title->React.string
        </a>
        <div
            className="w-60 h-40 mx-auto mb-10 bg-gradient-to-b from-lite-gold-yellow via-mid-green to-indigo-dye"
            id=aid
        ></div>
    </div>
};