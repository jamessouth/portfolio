let file = (dict, key) => dict->Js.Dict.unsafeGet(key);
let filePath = file(Data.paths);

[@react.component]
let make = () => {
    <>
        <main>
            <About
                path=filePath("about")
            />
            <Port
                projects=Data.projects
            />
            <Articles
                path=filePath("articles")
            />
            <Contact
                links=Data.links
                path=filePath("contact")
            />
        </main>
        <Footer
            picPath=filePath("footPic")
            resPath=filePath("footRes")
            navLinks=Data.navLinks
        />
    </>
};